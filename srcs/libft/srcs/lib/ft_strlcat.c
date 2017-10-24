/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 00:24:51 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/22 15:30:02 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;
	size_t save;
	size_t save1;
	size_t save2;

	j = 0;
	i = 0;
	while (s1[j] != '\0')
		j++;
	save1 = ft_strlen(s1);
	save2 = ft_strlen(s2);
	save = j;
	while (s2[i] && i + save1 < n - 1)
	{
		s1[j] = s2[i];
		j++;
		i++;
	}
	if (j != save)
		s1[j] = '\0';
	if (save1 > n)
		return (save2 + n);
	return (save1 + save2);
}
