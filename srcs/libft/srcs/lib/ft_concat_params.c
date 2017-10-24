/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 11:30:24 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/22 18:27:17 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	size_t	l;
	int		j;
	char	*a;

	a = "\0";
	j = 0;
	l = 0;
	i = 2;
	if (argc == 1)
		return ("\0");
	while (i < argc)
		l = l + ft_strlen(argv[i++]);
	if (!(a = malloc(sizeof(char) * l + 1)))
		return ("\0");
	i = 2;
	while (i < argc)
		ft_strcat(a, argv[i++]);
	return (a);
}
