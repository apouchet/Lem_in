/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:02:29 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/14 12:27:04 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(a = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		a[i] = (char)s[start];
		i++;
		start++;
	}
	a[i] = '\0';
	return (a);
}
