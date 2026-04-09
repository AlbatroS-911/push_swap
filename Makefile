# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/06 15:44:06 by anjaraan          #+#    #+#              #
#    Updated: 2026/04/09 10:22:02 by tokrabem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -g -O0 -Wall -Wextra -Werror

SRC = push_swap.c is_sorted.c movement_push.c movement_rotate.c movement_reverse_rotate.c \
      movement_swap.c disorder_metric.c ft_sqrt.c ft_last_node.c adaptive_strategy.c simple_strategy.c \
	  simple_strategy_utils.c ft_stack_size.c set_above_median.c medium_strategy.c medium_strategy_utils.c \
	  complex_strategy.c complex_strategy_utils.c complex_init_push.c complex_set_strategy.c complex_set_cost.c \
	  bench.c bench_movement_push.c bench_movement_reverse_rotate.c bench_movement_rotate.c bench_movement_swap.c \
	  push_swap_utils.c parsing_check_bench.c parsing_check_flag.c parsing_ft_strcmp.c parsing_function.c parsing_print_error.c \
	  parsing_stack_utils.c parsing_utils.c 

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)
	
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean 
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re