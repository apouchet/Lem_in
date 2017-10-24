/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:07:18 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/14 17:30:49 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*a;
	size_t			i;

	i = 0;
	if (n <= 0)
		return (NULL);
	a = (unsigned char*)s;
	while (i < (n - 1) && a[i] != (unsigned char)c)
		i++;
	if (a[i] == (unsigned char)c)
		return (&a[i]);
	return (NULL);
}
