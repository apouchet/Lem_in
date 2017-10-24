/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 13:53:51 by apouchet          #+#    #+#             */
/*   Updated: 2017/06/30 13:53:52 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void			ft_debut(t_va *val)
{
	val->piece = 0;
	val->start = -2;
	val->end = -2;
	val->etape = 0;
	if (!(val->com = (char*)malloc(sizeof(char) * (size_t)(2))))
		ft_exit(val, -1);
	val->com[0] = '\0';
}

int				*ft_deplacement(t_va *val, int *step)
{
	int i;

	i = 0;
	while (i < val->fourm + 1)
		step[i++] = -1;
	while (step[val->fourm - 1] != -2)
	{
		i = 0;
		while (i < val->fourm)
		{
			if (((step[i - 1] > 1 || step[i - 1] == -2) && step[i] == -1)
				|| (step[i] == -1 && i == 0))
				step[i] = 1;
			else if (step[i] > 0 && val->chem[(int)step[i]] != val->end)
				step[i]++;
			if (step[i] > 0)
				ft_printf("L%d-%s ", i + 1, val->nom[val->chem[(int)step[i]]]);
			if (val->chem[(int)step[i]] == val->end)
				step[i] = -2;
			i++;
		}
		ft_printf("\n");
	}
	return (step);
}

void			ft_exit(t_va *val, int mode)
{
	val->etape++;
	if (mode == -1)
		ft_printf("Error\n");
	if (mode < 100)
		exit(0);
}
