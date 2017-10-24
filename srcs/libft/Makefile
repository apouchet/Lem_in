# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apouchet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 05:07:37 by apouchet          #+#    #+#              #
#    Updated: 2016/11/22 18:30:23 by apouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Weverything -Wall -Werror -Wextra

NAME = libft.a

LIB = ./srcs/lib/ft_putnbr.c ./srcs/lib/ft_isascii.c ./srcs/lib/ft_strcpy.c \
	./srcs/lib/ft_strncpy.c ./srcs/lib/ft_isdigit.c ./srcs/lib/ft_putstr.c \
	./srcs/lib/ft_strlen.c ./srcs/lib/ft_strdup.c ./srcs/lib/ft_strrchr.c \
	./srcs/lib/ft_atoi.c ./srcs/lib/ft_isprint.c ./srcs/lib/ft_strcat.c \
	./srcs/lib/ft_isalnum.c ./srcs/lib/ft_putchar.c ./srcs/lib/ft_strchr.c \
	./srcs/lib/ft_tolower.c ./srcs/lib/ft_strncat.c ./srcs/lib/ft_toupper.c \
	./srcs/lib/ft_isalpha.c ./srcs/lib/ft_strcmp.c ./srcs/lib/ft_strncmp.c \
	./srcs/lib/ft_memmove.c ./srcs/lib/ft_strlcat.c ./srcs/lib/ft_strstr.c \
	./srcs/lib/ft_memset.c ./srcs/lib/ft_memcpy.c ./srcs/lib/ft_memccpy.c \
	./srcs/lib/ft_strmapi.c ./srcs/lib/ft_memchr.c ./srcs/lib/ft_strsub.c \
	./srcs/lib/ft_memcmp.c ./srcs/lib/ft_bzero.c ./srcs/lib/ft_strnstr.c \
	./srcs/lib/ft_memdel.c ./srcs/lib/ft_strdel.c ./srcs/lib/ft_strclr.c \
	./srcs/lib/ft_strnew.c ./srcs/lib/ft_strsplit.c ./srcs/lib/ft_putchar_fd.c \
	./srcs/lib/ft_strjoin.c ./srcs/lib/ft_putstr_fd.c ./srcs/lib/ft_concat_params.c \
	./srcs/lib/ft_putendl.c ./srcs/lib/ft_putendl_fd.c ./srcs/lib/ft_putnbr_fd.c \
	./srcs/lib/ft_ultimate_range.c ./srcs/lib/ft_striter.c ./srcs/lib/ft_itoa.c \
	./srcs/lib/ft_striteri.c ./srcs/lib/ft_strequ.c ./srcs/lib/ft_strnequ.c \
	./srcs/lib/ft_memalloc.c ./srcs/lib/ft_strtrim.c ./srcs/lib/ft_strmap.c \
	./srcs/lib/ft_lstnew.c ./srcs/lib/ft_lstdelone.c ./srcs/lib/ft_lstdel.c \
	./srcs/lib/ft_lstiter.c ./srcs/lib/ft_lstadd.c ./srcs/lib/ft_lstmap.c \
	./srcs/lib/ft_strupcase.c ./srcs/lib/ft_strlowcase.c ./srcs/lib/ft_strcapitalize.c \

PRINT = ./srcs/print/ft_printf.c ./srcs/print/octo.c ./srcs/print/decalage.c \
	./srcs/print/autre.c ./srcs/print/ft_printf_char.c ./srcs/print/ft_printf_nb.c \
	./srcs/print/ft_nombre.c

GET = ./srcs/get/get_next_line.c\

OBJL = $(LIB:.c=.o)

OBJP = $(PRINT:.c=.o)

OBJG = $(GET:.c=.o)

all: $(NAME) 

$(NAME) : $(OBJL) $(OBJP) $(OBJG)
	ar rc $(NAME) $(OBJL) $(OBJG) $(OBJP)
	ranlib libft.a

norm :
	clear
	norminette -R CheckForbiddenSourceHeader *.c

clean :
	rm -f srcs/lib/*.o
	rm -f srcs/get/*.o
	rm -f srcs/print/*.o

re : fclean all

fclean : clean
	rm -f $(NAME)
