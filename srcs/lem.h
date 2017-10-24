/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:09:12 by apouchet          #+#    #+#             */
/*   Updated: 2017/06/29 15:09:13 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "libft/lib.h"

typedef struct	s_va
{
	int			fourm;
	char		nom[1000][100];
	int			pos[1000][2];
	int			lien[1000][1000];
	int			start;
	int			end;
	int			piece;
	int			poids[1000];
	int			chem[1000];
	char		*com;
	int			etape;
	char		padding[4];
}				t_va;

void			ft_exit(t_va *val, int mode);

int				ft_existe_pos(t_va *val);

int				tri_nb(char *tab, t_va *val, int *i);

int				verif_piece(char *tab, t_va *val);

void			ft_zero_lien(t_va *val);

int				ft_existe_name(char *tab, t_va *val);

int				ft_existe_lien(t_va *val, int nb, int nbr);

int				verif_lien(char *tab, t_va *val);

void			poids_zero(t_va *val);

int				verif_poids_piece(t_va *val, int piece, int po);

void			ft_poids_piece(t_va *val);

void			ft_chemin(t_va *val);

int				*ft_deplacement(t_va *val, int *step);

void			ft_debut(t_va *val);

#endif
