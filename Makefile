# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spochez <spochez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/24 19:33:48 by spochez           #+#    #+#              #
#    Updated: 2015/01/24 20:58:57 by spochez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_add_flag.c			\
	  ft_atoi.c				\
	  ft_base_convert.c		\
	  ft_bzero.c			\
	  ft_fill_tab.c			\
	  ft_fst_flag.c			\
	  ft_get_lm.c			\
	  ft_hexa_convert.c		\
	  ft_isdigit.c			\
	  ft_maxtoa.c			\
	  ft_memset.c			\
	  ft_nb_conversions.c	\
	  ft_printf.c			\
	  ft_putchar.c			\
	  ft_putstr.c			\
	  ft_scd_flags.c		\
	  ft_sflags.c			\
	  ft_split_bits.c		\
	  ft_strchr.c			\
	  ft_strdup.c			\
	  ft_strlen.c			\
	  ft_strrev.c			\
	  ft_to_print.c			\
	  ft_treat_prec.c		\
	  ft_treat_types.c		\
	  ft_treat_void.c		\
	  ft_types.c			\
	  ft_uinmaxtoa.c		\
	  ft_wchrtreat.c		\

OBJ = $(SRC:.c=.o) 

CFLAGS += -I -Wall -Werror -Wextra -I

all : $(NAME)
	gcc -c $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -f $(OBJ)

fclean :
	rm -f $(OBJ) $(NAME) a.out

re : fclean all
