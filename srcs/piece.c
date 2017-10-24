/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 13:52:47 by apouchet          #+#    #+#             */
/*   Updated: 2017/06/30 13:52:49 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		ft_existe_pos(t_va *val)
{
	int i;

	i = 0;
	while (i < val->piece)
	{
		if (ft_strequ(val->nom[val->piece], val->nom[i]) ||
			(val->pos[val->piece][0] == val->pos[i][0] &&
			val->pos[val->piece][1] == val->pos[i][1]))
			ft_exit(val, -1);
		i++;
	}
	return (0);
}

int		tri_nb(char *tab, t_va *val, int *i)
{
	char	*tmp;
	int		nb;
	int		j;

	j = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * 13)))
		return (1);
	while (tab[i[0]] != ' ' && tab[i[0]])
	{
		if (ft_isdigit(tab[i[0]]))
		{
			tmp[j++] = tab[i[0]++];
			tmp[j] = '\0';
		}
		else
			ft_exit(val, -1);
	}
	nb = ft_atoi(tmp);
	free(tmp);
	return (nb);
}

int		verif_piece(char *tab, t_va *val)
{
	int i;
	int	j;

	j = 0;
	i = 0;
	while (tab[i] != ' ')
	{
		if (tab[i] == ' ' || tab[i] == '-' || tab[0] == 'L')
			ft_exit(val, -1);
		val->nom[val->piece][j++] = tab[i++];
		val->nom[val->piece][j] = '\0';
	}
	i++;
	val->pos[val->piece][0] = tri_nb(tab, val, &i);
	i++;
	val->pos[val->piece][1] = tri_nb(tab, val, &i);
	ft_existe_pos(val);
	if (val->start == -1)
		val->start = val->piece;
	if (val->end == -1)
		val->end = val->piece;
	return (0);
}
