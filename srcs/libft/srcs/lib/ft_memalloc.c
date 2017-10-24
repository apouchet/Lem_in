/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:01:24 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/13 17:25:32 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	if (!(a = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	if (a == NULL)
		return (NULL);
	a[size] = '\0';
	ft_bzero(a, size);
	return (a);
}
