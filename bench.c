/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:27:31 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/08 19:52:46 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

static void	init_move_bench(t_bench *bench)
{
	bench->pa = 0;
	bench->pb = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->print_moves = 0;
}

static void	print_bench_details(float disorder, char *strat_type,
		t_bench *bench, int total_ops)
{
	ft_printf("[bench] disorder : %f%%\n", disorder * 100);
	ft_printf("[bench] strategy : %s\n", strat_type);
	ft_printf("[bench] total_ops : %d\n", total_ops);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", bench->sa,
		bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}

void	show_bench(t_stack **a, t_stack **b)
{
	float	disorder_index;
	t_bench	*bench;

	bench = malloc(sizeof(t_bench));
	if (!bench)
		return ;
	init_move_bench(bench);
	disorder_index = compute_disorder(*a);
	if (disorder_index < 0.2)
		print_bench_details(disorder_index, "Adaptive / O(n²)", bench,
			simple_strategy(a, b, bench));
	else if (disorder_index >= 0.2 && disorder_index < 0.5)
		print_bench_details(disorder_index, "Adaptive / O(n√n)", bench,
			medium_strategy(a, b, bench));
	else
		print_bench_details(disorder_index, "Adaptive / O(n log n)", bench,
			complex_strategy(a, b, bench));
	free(bench);
}
