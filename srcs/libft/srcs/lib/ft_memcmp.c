/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:34:00 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/14 15:31:31 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void *s1, void *s2, size_t n)
{
	char	*a;
	char	*b;
	size_t	i;

	if (n <= 0)
		return (0);
	i = 0;
	a = (char*)s1;
	b = (char*)s2;
	while (i < n && *a == *b)
	{
		a++;
		b++;
		i++;
	}
	if (i != n)
		return ((unsigned char)*a - (unsigned char)*b);
	return (0);
}
