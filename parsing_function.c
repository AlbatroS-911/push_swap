/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:55:05 by anjaraan          #+#    #+#             */
/*   Updated: 2026/04/20 23:06:26 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "bench.h"

void	split_and_loop(char *input, t_stack **stack, t_error *error)
{
	char	**tokens;
	int		i;
	long	value;

	tokens = ft_split(input, ' ');
	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		if (!is_number(tokens[i]))
			print_error(stack, error);
		value = ft_atoi(tokens[i]);
		if (value < -2147483648 || value > 2147483647)
			print_error(stack, error);
		append_node(stack, value);
		if (check_duplicates(*stack) == 0)
			print_error(stack, error);
		i++;
	}
	free_tokens(tokens);
}

void	parse_int_input(char **argv, t_stack **stack, int start, int end, t_error *error)
{
	long	value;
	
	while (start < end)
	{
		if (ft_strchr(argv[start], ' '))
			split_and_loop(argv[start], stack, error);
		else
		{
			if (!is_number(argv[start]))
				print_error(stack, error);
			value = ft_atoi(argv[start]);
			if (value < -2147483648 || value > 2147483647)
				print_error(stack, error);
			append_node(stack, value);
			if (check_duplicates(*stack) == 0)
				print_error(stack, error);
		}
		start++;
	}
}

int	valide_flag(int argc, char **argv, t_stack **stack, t_error *error)
{
	if (check_duplicate_flag(argv, argc) == 0
		|| check_duplicate_bench_flag(argv, argc) == 0)
	{
		print_error(stack, error);
		return (0);
	}
	if (check_flag_position(argc, argv) == 0 || check_bench_flag_position(argc,
			argv) == 0)
	{
		print_error(stack, error);
		return (0);
	}
	return (1);
}

void	parse_all_input(int argc, char **argv, t_stack **stack,
		t_error *error)
{
	int	i;
	
	error->flagBench->flag = "";
	error->flagBench->bench = "";
	if (!valide_flag(argc, argv, stack, error))
		return ;
	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]))
			error->flagBench->flag = argv[i];
		else if (is_bench(argv[i]))
			error->flagBench->bench = argv[i];
		else
			parse_int_input(argv, stack, i, i + 1, error);
		i++;
	}
}
