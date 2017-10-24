/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:22:50 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/13 17:49:27 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_rev(void *dst, void *src, size_t n)
{
	char *a;
	char *b;

	a = (char*)dst;
	b = (char*)src;
	while (n--)
		a[n] = b[n];
	return (a);
}

void		*ft_memmove(void *dst, void *src, size_t len)
{
	if (dst > src)
		dst = ft_rev(dst, src, len);
	if (dst < src)
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
