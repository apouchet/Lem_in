/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:59:06 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/13 22:00:32 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nb(int nb)
{
	size_t i;

	i = 1;
	if (nb < 0)
		i++;
	while (nb > 9 || nb < -9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	long int	nb;
	size_t		i;
	char		*a;

	nb = n;
	i = ft_nb(n);
	if (!(a = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	a[i] = '\0';
	i--;
	if (n < 0)
	{
		nb = -nb;
		a[0] = '-';
	}
	while (nb >= 10)
	{
		a[i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	a[i] = (char)nb + 48;
	return (a);
}
