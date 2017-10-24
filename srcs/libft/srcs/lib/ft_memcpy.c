/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:26:58 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/13 17:26:40 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char *a;
	unsigned char *b;

	a = (unsigned char*)dest;
	b = (unsigned char*)src;
	while (n > 0)
	{
		*a = *b;
		a++;
		b++;
		n--;
	}
	return (dest);
}
