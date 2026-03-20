# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/17 14:49:55 by tokrabem          #+#    #+#              #
#    Updated: 2026/03/19 11:28:18 by tokrabem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_putnbr_base.c ft_printf.c ft_un_int.c ft_putstr_fd.c\
		ft_putchar_fd.c ft_strlen.c ft_print_add.c ft_put_float.c

CC = cc
FLAGS = -Wextra -Werror -Wall
NAME = libftprintf.a

OBJ = $(SRC:.c=.o)

all		: $(NAME)

$(NAME) : $(OBJ)
	ar -rsc $(NAME) $(OBJ)

%.o		: %.c
	$(CC) $(FLAGS) -c $< -o $@ 

clean	:
	rm -rf $(OBJ)

fclean :	clean
	rm -f $(NAME)
	
re : fclean all 

.PHONY : all clean fclean re
