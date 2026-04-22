/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:47:56 by anjaraan          #+#    #+#             */
/*   Updated: 2026/04/22 17:23:43 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"
# include "push_swap.h"
# include "bench.h"

typedef struct s_flagBench
{
	char	*flag;
	char	*bench;
}			t_flagBench;

typedef struct s_error
{
	t_bench		*bench;
	t_flagBench	*flag_bench;
}			t_error;

typedef struct s_range
{
	int	start;
	int	end;
}			t_range;

void		parse_int_input(char **argv, t_stack **stack, t_range range,
				t_error *error);
t_stack		*new_node(int value);
void		free_tokens(char **tokens);
void		append_node(t_stack **stack, int value);
int			check_duplicates(t_stack *stack);
void		init_stack(t_stack **stack, int *values, int count);
void		print_stack(t_stack *stack);
void		free_stack(t_stack **stack);
void		print_error(t_stack **stack, t_error *error);
int			is_number(char *str);
void		split_and_loop(char *input, t_stack **stack, t_error *error);
int			check_flag(const char *str);
int			is_flag(const char *str);
int			check_duplicate_flag(char **argv, int argc);
void		parse_all_input(int argc, char **argv, t_stack **stack,
				t_error *error);
int			check_flag_position(int argc, char **argv);
int			check_strat_flag_presence(int argc, char **argv);
int			check_bench_flag(const char *str);
int			is_bench(const char *str);
int			check_duplicate_bench_flag(char **argv, int argc);
int			valide_flag(int argc, char **argv, t_stack **stack, t_error *error);
int			check_bench_flag_position(int argc, char **argv);
int			check_flag_bench_presence(int argc, char **argv);
int			ft_strcmp(const char *s1, const char *s2);

#endif