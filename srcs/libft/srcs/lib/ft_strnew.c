/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:56:07 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/13 17:42:08 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	if (!(a = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	a[size] = '\0';
	while (i < size)
	{
		a[i] = '\0';
		i++;
	}
	return (a);
}
