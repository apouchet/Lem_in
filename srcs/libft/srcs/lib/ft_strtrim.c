/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 20:27:49 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/14 17:24:48 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*a;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (!s[i])
		return (ft_strnew(i));
	j = 0;
	while (s[i + j + 1])
		j++;
	while (s[i + j] == ' ' || s[i + j] == '\n' || s[i + j] == '\t')
		j--;
	if (!(a = (char*)malloc(sizeof(char) * j + 2)))
		return (NULL);
	j++;
	while (k++ != j)
		a[k - 1] = (char)s[i + k - 1];
	a[j] = '\0';
	return (a);
}
