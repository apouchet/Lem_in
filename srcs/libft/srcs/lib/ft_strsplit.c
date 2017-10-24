/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:11:55 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/13 20:36:27 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word(const char *s, char c)
{
	size_t i;

	i = 1;
	while (*s == c)
		s++;
	while (*s != '\0')
	{
		i++;
		while (*s != c && *s != '\0')
			s++;
		while (*s == c)
			s++;
	}
	return (i);
}

static char		*ft_len(const char *s, char c)
{
	int		i;
	size_t	j;
	char	*a;

	i = 0;
	j = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (!(a = (char*)malloc(sizeof(char) * (size_t)(i + 1))))
		return (NULL);
	i = 0;
	while (s[i] != c && s[i] != '\0')
		a[j++] = s[i++];
	a[j] = '\0';
	return (a);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**a;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s == (NULL))
		return (NULL);
	i = ft_word(s, c);
	j = 0;
	k = 0;
	if (!(a = (char**)malloc(sizeof(char*) * i + 1)))
		return (NULL);
	while (s[k] == c)
		k++;
	while (s[k] != '\0' && j <= i && s[k] != c)
	{
		a[j] = ft_len(&s[k], c);
		while (s[k] != c && s[k])
			k++;
		while (s[k] == c)
			k++;
		j++;
	}
	a[j] = NULL;
	return (a);
}
