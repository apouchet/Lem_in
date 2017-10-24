/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 04:34:09 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/13 22:19:27 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	long int a;

	a = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		a = -a;
	}
	if (a < 10)
		ft_putchar('0' + (int)a);
	if (a >= 10)
	{
		ft_putnbr((int)a / 10);
		ft_putchar('0' + (a % 10));
	}
}
