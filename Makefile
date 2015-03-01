# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spochez <spochez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/24 19:33:48 by spochez           #+#    #+#              #
#    Updated: 2015/02/05 08:11:15 by spochez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_add_flags.c		\
	  ft_atoi.c				\
	  ft_base_convert.c		\
	  ft_bzero.c			\
	  ft_fill_tab.c			\
	  ft_get_char.c			\
	  ft_get_lm.c			\
	  ft_get_types.c 		\
	  ft_get_precision.c 	\
	  ft_hexa_convert.c		\
	  ft_isdigit.c			\
	  ft_isvalid.c 			\
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
	  ft_strsplit.c 		\
	  ft_strsub.c 			\
	  ft_strrev.c			\
	  ft_strwlen.c 			\
	  ft_to_print.c			\
	  ft_treat_instauint.c	\
	  ft_treat_null.c 		\
	  ft_treat_prec.c		\
	  ft_treat_types.c		\
	  ft_treat_void.c		\
	  ft_types.c			\
	  ft_uinmaxtoa.c		\
	  ft_wchrtreat.c		\
	  main.c 				\

OBJ = $(SRC:.c=.o) 

CFLAGS += -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
	gcc -c $(CFLAGS) $(SRC)
	gcc -o a.out *.o
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	./a.out

clean :
	rm -f $(OBJ)

fclean :
	rm -f $(OBJ) $(NAME) a.out

re : fclean all
