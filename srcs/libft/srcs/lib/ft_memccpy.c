/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:55:56 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/13 17:25:45 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void *src, int c, size_t n)
{
	char *a;
	char *b;

	a = (char*)dest;
	b = (char*)src;
	while (n > 0)
	{
		*a = *b;
		if (*a == c)
		{
			a++;
			return (a);
		}
		a++;
		b++;
		n--;
	}
	return (NULL);
}
