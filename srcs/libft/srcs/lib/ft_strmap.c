/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 22:38:57 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/22 16:28:36 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*a;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (!(a = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		a[i] = (f)(s[i]);
		i++;
	}
	a[i] = '\0';
	return (a);
}
