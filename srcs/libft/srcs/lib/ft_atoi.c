/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 00:38:50 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/13 22:19:35 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int i;
	int neg;
	int nb;

	neg = 0;
	i = 0;
	nb = 0;
	while (str[i] == 32 || str[i] == 9 || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\n' || str[i] == 43 || str[i] == 45 || str[i] == '\r')
	{
		if ((str[i] == 43 || str[i] == 45) &&
			(str[i + 1] < '0' || str[i + 1] > '9'))
			return (nb);
		i++;
	}
	if (i > 0 && str[i - 1] == '-')
		neg = 1;
	while (str[i] >= '0' && str[i] <= '9')
		nb = (nb * 10) + (str[i++] - 48);
	if (neg == 1)
		nb = nb * (-1);
	return (nb);
}
