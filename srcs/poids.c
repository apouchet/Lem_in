/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poids.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 16:46:50 by apouchet          #+#    #+#             */
/*   Updated: 2017/07/03 16:46:53 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	poids_zero(t_va *val)
{
	int	i;

	i = 0;
	while (i <= val->piece)
	{
		val->poids[i] = -1;
		i++;
	}
	val->poids[val->end] = 0;
}

int		verif_poids_piece(t_va *val, int piece, int po)
{
	int i;

	i = 0;
	while (val->lien[piece][i] != -1)
	{
		if (val->poids[val->lien[piece][i]] == po)
			return (1);
		i++;
	}
	return (0);
}

void	ft_poids_piece(t_va *val)
{
	int i;
	int p;

	i = 0;
	p = 0;
	poids_zero(val);
	while (val->poids[val->start] == -1)
	{
		i = 0;
		while (i <= val->piece)
		{
			if (verif_poids_piece(val, i, p) && val->poids[i] == -1)
				val->poids[i] = p + 1;
			i++;
		}
		p++;
		if (p > val->piece + 1)
			ft_exit(val, -1);
	}
}

void	ft_chemin(t_va *val)
{
	int i;
	int	j;
	int	min;
	int	nb;

	j = 0;
	i = 1;
	val->chem[0] = val->start;
	while (val->chem[i - 1] != val->end)
	{
		min = val->chem[i - 1];
		j = 0;
		while (val->lien[val->chem[i - 1]][j] != -1)
		{
			nb = val->poids[val->lien[val->chem[i - 1]][j]];
			if (nb < val->poids[min] && nb != -1)
				min = val->lien[val->chem[i - 1]][j];
			j++;
		}
		val->chem[i] = min;
		i++;
	}
	val->etape = i;
}
