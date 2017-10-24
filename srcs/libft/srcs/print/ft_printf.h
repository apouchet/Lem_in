/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:09:28 by apouchet          #+#    #+#             */
/*   Updated: 2017/03/23 19:09:30 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include "../lib/libft.h"

typedef struct				s_val
{
	char					buff[552];
	long long				nb;
	unsigned long long		nbr;
	int						b;
	int						prec;
	int						precision;
	int						ldc;
	int						ldchamp;
	int						len;
	int						type;
	int						base;
	int						maj;
	int						tmp;
	int						ltotal;
	int						ldif;
	int						lon;
	int						lonlon;
	int						shortshort;
	int						shor;
	int						plus;
	int						moins;
	int						zero;
	int						tag;
	int						space;
	int						signe;
	int						po;
	char					p[10];
	char					padding[2];
}							t_val;

int							ft_printf(char *str, ...);

void						ft_decalage(t_val *a, int c);

void						ft_init(t_val *a);

int							ft_len(int c);

void						ft_affich(t_val *a);

int							largeur_champ(int j, t_val *a);

int							precision(int j, t_val *a);

void						ft_buff_str(char *str, t_val *a, int len);

void						ft_str(t_val *a, va_list ap);

void						ft_str_unicode(t_val *a, va_list ap);

void						lettre(t_val *a, va_list ap, int flag);

int							nb(char *str, int i, t_val *a, int mode);

void						ft_nombre(t_val *a, va_list ap, char flag);

char						*ft_itoa_base(long long int nb, int base, int maj);

char						*ft_itoa_unsigned_base(unsigned long long int nb,
	int base, int maj);

long long int				signe(t_val *a, va_list ap);

unsigned long long			unsigne(t_val *a, va_list ap, int flag);

#endif
