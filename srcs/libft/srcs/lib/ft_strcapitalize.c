/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 09:45:50 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/22 18:17:24 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
			str[i] = str[i] + 32;
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 64 && str[i + 1] > 96 && str[i + 1] < 123)
			if (str[i] < 48 || str[i] > 57)
				str[i + 1] = str[i + 1] - 32;
		if (str[i] > 122 && str[i + 1] > 96 && str[i + 1] < 123)
			str[i + 1] = str[i + 1] - 32;
		if (str[i] > 90 && str[i] < 97 && str[i + 1] > 96 && str[i + 1] < 123)
			str[i + 1] = str[i + 1] - 32;
		if (str[0] > 96 && str[0] < 123)
			str[0] = str[0] - 32;
		i++;
	}
	return (str);
}
