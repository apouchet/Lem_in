/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:06:50 by apouchet          #+#    #+#             */
/*   Updated: 2016/11/22 18:23:55 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					get_next_line(const int fd, char **line);

int					ft_ultimate_range(int **range, int min, int max);

char				*ft_strupcase(char *str);

char				*ft_strlowcase(char *str);

char				*ft_concat_params(int argc, char **argv);

char				*ft_strcapitalize(char *str);

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstnew(void *content, size_t content_size);

int					ft_toupper(int c);

int					ft_tolower(int c);

char				*ft_strtrim(char const *s);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strstr(char *big, char *little);

char				**ft_strsplit(const char *s, char c);

char				*ft_strrchr(char *s, int c);

char				*ft_strnstr(char *big, char *little, size_t n);

char				*ft_strnew(size_t size);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strncpy(char *dst, const char *src, size_t len);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strncat(char *s1, const char *s2, size_t n);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				*ft_strmap(char const *s, char (*f)(char));

size_t				ft_strlen(const char *s);

size_t				ft_strlcat(char *s1, const char *s2, size_t n);

char				*ft_strjoin(char const *s1, char const *s2);

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				ft_striter(char *s, void (*f)(char *));

int					ft_strequ(char const *s1, char const *s2);

char				*ft_strdup(const char *s1);

void				ft_strdel(char **as);

char				*ft_strcpy(char *dest, const char *src);

int					ft_strcmp(const char *s1, const char *s2);

void				ft_strclr(char *s);

char				*ft_strchr(char *s, int c);

char				*ft_strcat(char *s1, const char *s2);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr(char *str);

void				ft_putnbr_fd(int nb, int fd);

void				ft_putnbr(int nb);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putendl(char const *s);

int					ft_putchar(int c);

char				*ft_strjoin_free(char *s1, char *s2, int mode);

void				ft_putstr_fd(const char *s, int fd);

void				*ft_memset(void *s, int c, size_t n);

void				*ft_memmove(void *dst, void *src, size_t len);

void				ft_memdel(void **ap);

void				*ft_memcpy(void *dest, void *src, size_t n);

int					ft_memcmp(void *s1, void *s2, size_t n);

void				*ft_memchr(void *s, int c, size_t n);

void				*ft_memccpy(void *dest, void *src, int c, size_t n);

void				*ft_memalloc(size_t size);

int					ft_isprint(int c);

int					ft_isdigit(int c);

int					ft_isascii(int c);

int					ft_isalpha(int c);

int					ft_isalnum(int c);

int					ft_atoi(char *str);

void				ft_bzero(void *s, size_t n);

char				*ft_itoa(int n);

#endif