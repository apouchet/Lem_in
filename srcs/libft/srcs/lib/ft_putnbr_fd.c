/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:17:36 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/13 18:22:46 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long int a;

	a = nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		a = -a;
	}
	if (a < 10)
		ft_putchar_fd((char)('0' + a), fd);
	if (a >= 10)
	{
		ft_putnbr_fd((int)(a / 10), fd);
		ft_putchar_fd('0' + (a % 10), fd);
	}
}
