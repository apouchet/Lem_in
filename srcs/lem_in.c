/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:35:30 by apouchet          #+#    #+#             */
/*   Updated: 2017/06/29 14:35:34 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static int		ft_word(char *tab)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (tab[i])
	{
		while (tab[i] == ' ')
			i++;
		if (tab[i] > 32 && tab[i] < 127 && tab[i] != 'L' && tab[i] != '#' &&
			tab[i] != ' ' && (i == 0 || tab[i - 1] == ' '))
			nb++;
		i++;
	}
	return (nb);
}

static void		ft_etape_un(t_va *val, char *line, int word)
{
	if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
	{
		if (ft_strequ(line, "##start") && val->start == -2 &&
			val->etape == 1 && val->end != -1)
			val->start = -1;
		else if (ft_strequ(line, "##end") && val->end == -2 &&
			val->etape == 1 && val->start != -1)
			val->end = -1;
		else
			ft_exit(val, -1);
	}
	else if (word == 3 && val->etape == 1)
	{
		verif_piece(line, val);
		val->piece++;
	}
	else if (word == 1 && val->etape == 1 && val->start != -2 && val->end != -2)
	{
		val->etape++;
		ft_zero_lien(val);
		verif_lien(line, val);
	}
	else if (line[0] != '#')
		ft_exit(val, -1);
}

static int		ft_etape_zero(t_va *val, char *line, int mode)
{
	int i;

	i = 0;
	if (mode == 1)
	{
		val->fourm = tri_nb(line, val, &i);
		if (val->fourm < 1 || val->fourm > 10000)
			ft_exit(val, -1);
		val->etape = 1;
	}
	else
	{
		val->com = ft_strjoin_free(val->com, &line[1], 1);
		val->com = ft_strjoin_free(val->com, "\n", 1);
	}
	return (0);
}

static void		ft_pars(t_va *val)
{
	char	*l;
	int		word;

	while (get_next_line(0, &l) > 0)
	{
		word = ft_word(l);
		if (l[0] == '#' && l[1] != '#')
			word = ft_etape_zero(val, l, 0);
		if (l[0] == '\0')
			break ;
		else if (l[0] == ' ' || (l[ft_strlen(l) - 1] == ' ' && l[0] != '#')
			|| val->piece > 1000)
			ft_exit(val, -1);
		else if (word == 1 && val->etape == 0 && l[0] != '#')
			ft_etape_zero(val, l, 1);
		else if (val->etape == 1)
			ft_etape_un(val, l, word);
		else if ((word == 1 || l[0] == '#') && val->etape == 2 &&
			val->start >= 0 && val->end >= 0)
			verif_lien(l, val);
		else if (l[0] != '#')
			ft_exit(val, -1);
		free(l);
	}
	free(l);
}

int				main(void)
{
	t_va	val;
	int		*step;

	ft_debut(&val);
	ft_pars(&val);
	if (!(step = (int*)malloc(sizeof(int) * (size_t)(val.fourm + 1))))
		ft_exit(&val, -1);
	if (val.start >= 0 && val.end >= 0 && val.etape == 2)
	{
		ft_poids_piece(&val);
		ft_chemin(&val);
		if (val.com[0] != '\0')
			ft_printf("%s\n", val.com);
		step = ft_deplacement(&val, step);
	}
	else
		ft_exit(&val, -1);
	free(step);
	free(val.com);
	return (0);
}
