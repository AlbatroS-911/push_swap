/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:50:47 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/18 06:34:34 by tokrabem         ###   ########.fr       */
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
static void	check_and_free(t_stack **a, t_stack **b, t_bench *bench,
		t_flagBench *flag_bench)
{
	if (!check_bench_flag(flag_bench->bench))
		flag_selector(a, b, bench, flag_bench);
	else
		show_bench(a, b, flag_bench->flag);
	free_stack(a);
	free_stack(b);
	free(bench);
	free(flag_bench);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_bench		*bench;
	t_flagBench	*flag_bench;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	bench = malloc(sizeof(t_bench));
	if (!bench)
		free(bench);
	flag_bench = malloc(sizeof(t_bench));
	if (!flag_bench)
		free(flag_bench);
	bench->print_moves = 1;
	parse_all_input(argc, argv, &a, flag_bench);
	check_and_free(&a, &b, bench, flag_bench);
	return (0);
}
