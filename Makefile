# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apouchet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/30 13:56:30 by apouchet          #+#    #+#              #
#    Updated: 2017/06/30 13:56:32 by apouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Weverything -Wall -Werror -Wextra

LIB = ./srcs/libft/

LIBFT = ./srcs/libft/libft.a

NAME = lem-in

SRC = ./srcs/lem_in.c ./srcs/piece.c ./srcs/fin.c ./srcs/lien.c ./srcs/poids.c\

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME) : $(OBJ)
	make -C $(LIB)
	gcc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

norm :
	clear
	norminette -R CheckForbiddenSourceHeader *.c

clean :
	make clean -C $(LIB)
	rm -f $(OBJ)

re : fclean all

fclean : clean
	rm -f $(LIBFT)
	rm -f $(NAME)

