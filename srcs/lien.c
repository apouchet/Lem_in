/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lien.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 13:53:42 by apouchet          #+#    #+#             */
/*   Updated: 2017/06/30 13:53:43 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void			ft_zero_lien(t_va *val)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < val->piece + 1)
	{
		while (j < val->piece + 1)
		{
			val->lien[i][j] = -1;
			j++;
		}
		j = 0;
		i++;
	}
}

int				ft_existe_name(char *tab, t_va *val)
{
	int		i;

	i = 0;
	while (i < val->piece)
	{
		if (ft_strequ(tab, val->nom[i]))
			return (i);
		i++;
	}
	ft_exit(val, -1);
	return (-1);
}

int				ft_existe_lien(t_va *val, int nb, int nbr)
{
	int	i;

	i = 0;
	while (val->lien[nb][i] != -1 && i < 100)
	{
		if (val->lien[nb][i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

static int		verif_lien_tmp(int nb, int nbr, t_va *val)
{
	int j;

	j = 0;
	while (val->lien[nb][j] != -1)
		j++;
	val->lien[nb][j] = nbr;
	j = 0;
	while (val->lien[nbr][j] != -1)
		j++;
	val->lien[nbr][j] = nb;
	return (0);
}

int				verif_lien(char *tab, t_va *val)
{
	size_t	i;
	int		j;
	int		nb;
	int		nbr;
	char	tmp[100];

	i = 0;
	j = 0;
	if (tab[0] == '#')
		return (0);
	while (tab[i] != '-' && tab[i])
		tmp[j++] = tab[i++];
	tmp[j] = '\0';
	if (ft_strlen(tab) <= i)
		ft_exit(val, -1);
	nb = ft_existe_name(tmp, val);
	j = 0;
	i++;
	while (tab[i] != '-' && tab[i])
		tmp[j++] = tab[i++];
	tmp[j] = '\0';
	nbr = ft_existe_name(tmp, val);
	if (nbr == nb || ft_existe_lien(val, nb, nbr))
		ft_exit(val, -1);
	return (verif_lien_tmp(nb, nbr, val));
}
