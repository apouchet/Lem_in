/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 20:11:48 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/14 12:37:26 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	k;
	char	*a;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	k = ft_strlen(s1) + ft_strlen(s2);
	if (!(a = (char*)malloc(sizeof(char) * (k + 1))))
		return (NULL);
	while (s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	while (s2[j])
		a[i++] = s2[j++];
	a[i] = '\0';
	return (a);
}

char	*ft_strjoin_free(char *s1, char *s2, int mode)
{
	int		i;
	int		j;
	size_t	k;
	char	*a;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	k = ft_strlen(s1) + ft_strlen(s2);
	if (!(a = (char*)malloc(sizeof(char) * (k + 1))))
		return (NULL);
	while (s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	while (s2[j])
		a[i++] = s2[j++];
	a[i] = '\0';
	if (mode == 1 || mode == 3)
		free(s1);
	if (mode == 2 || mode == 3)
		free(s2);
	return (a);
}
