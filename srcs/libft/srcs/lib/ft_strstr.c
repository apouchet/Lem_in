/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:24:16 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/13 17:44:39 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *big, char *little)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char*)big);
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != '\0')
			j++;
		if (little[j] == '\0')
			return ((char*)&big[i]);
		i++;
	}
	return (NULL);
}
