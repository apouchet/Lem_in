/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:57:55 by apouchet          #+#    #+#             */
/*   Updated: 2017/01/10 17:57:56 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "../lib/libft.h"

static char		*ft_join(char *s1, char *s2)
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
	ft_bzero((void*)s2, BUFF_SIZE);
	free((void*)s1);
	a[i] = '\0';
	return (a);
}

static char		*ft_copie(char *dest, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		j++;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
	{
		str[i] = '\0';
		i++;
	}
	while (str[j + i])
	{
		dest[j] = str[j + i];
		str[j + i] = '\0';
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

static int		ft_rd(char **line, char **save, int fd, int *rd)
{
	char	*buff;

	buff = ft_memalloc(BUFF_SIZE + 1);
	if (ft_strlen(save[0]) != 0)
		line[0] = ft_join(line[0], save[0]);
	if (ft_strstr(line[0], "\n") != NULL)
	{
		save[0] = ft_copie(save[0], line[0]);
		free(buff);
		return (1);
	}
	else
	{
		rd[0] = (int)read(fd, buff, BUFF_SIZE);
		line[0] = ft_join(line[0], buff);
	}
	if ((rd[0] == 0 && !line[0][0]) || rd[0] == -1)
	{
		free(buff);
		return (rd[0]);
	}
	free(buff);
	return (-100);
}

int				get_next_line(const int fd, char **line)
{
	static char	*save;
	int			rd;
	int			res;

	rd = 1;
	if (fd <= -1 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (ft_strlen(save) == 0)
	{
		if (save)
			free(save);
		save = ft_memalloc(BUFF_SIZE + 1000);
	}
	line[0] = ft_memalloc(BUFF_SIZE + 1);
	while (rd != 0)
	{
		res = ft_rd(&line[0], &save, fd, &rd);
		if (res != -100)
			return (res);
	}
	return (1);
}
