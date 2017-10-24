/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:10:17 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/14 17:45:51 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char*)big);
	while (big[i] != '\0' && i + j < n)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && big[i + j] && i + j < n)
			j++;
		if (little[j] == '\0')
			return ((char*)&big[i]);
		i++;
	}
	return (NULL);
}
