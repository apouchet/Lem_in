/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 22:49:58 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/22 17:15:13 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*a;

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
		a[i] = (f)(i, s[i]);
		i++;
	}
	a[i] = '\0';
	return (a);
}
