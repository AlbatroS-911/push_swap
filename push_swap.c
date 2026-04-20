/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:50:47 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/20 19:42:53 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "push_swap.h"

static void	flag_selector(t_stack **a, t_stack **b, t_bench *bench,
		t_flagBench *flag_bench)
{
	if (check_flag(flag_bench->flag) == 1)
		simple_strategy(a, b, bench);
	else if (check_flag(flag_bench->flag) == 2)
		medium_strategy(a, b, bench);
	else if (check_flag(flag_bench->flag) == 3)
		complex_strategy_radix(a, b, bench);
	else if (check_flag(flag_bench->flag) == 4
		|| !(check_flag(flag_bench->flag)))
		adaptive_strategy(a, b);
}
static void	check_and_free(t_stack **a, t_stack **b, t_error *error)
{
	if (!check_bench_flag(error->flagBench->bench))
		flag_selector(a, b, error->bench, error->flagBench);
	else
		show_bench(a, b, error->flagBench->flag);
	free_stack(a);
	free_stack(b);
	free(error->bench);
	free(error->flagBench);
	free(error);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_error	*error;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	error = malloc(sizeof(t_error));
	if (!error)
		return (1);
	error->flagBench = malloc(sizeof(t_flagBench));
	error->bench = malloc(sizeof(t_bench));
	if (!error->flagBench || !error->bench)
	{
		free(error->bench);
		free(error->flagBench);
		free(error);
		return (1);
	}
	error->bench->print_moves = 1;
	parse_all_input(argc, argv, &a, error);
	check_and_free(&a, &b, error);
	return (0);
}
