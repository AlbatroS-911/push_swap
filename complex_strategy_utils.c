/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_strategy_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:10:26 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/08 18:16:47 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "complex_strategy.h"
#include "push_swap.h"

int	rotate_both(t_stack **a, t_stack **b, t_stack *cheap, t_bench *bench)
{
	int	ops;

	ops = 0;
	while (*a != cheap->target_node && *b != cheap)
	{
		bench_rr(bench);
		ops += rr(a, b);
	}
	set_above_median(*a);
	set_above_median(*b);
	return (ops);
}

int	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheap, t_bench *bench)
{
	int	ops;

	ops = 0;
	while (*a != cheap->target_node && *b != cheap)
	{
		bench_rrr(bench);
		ops += rrr(a, b);
	}
	set_above_median(*a);
	set_above_median(*b);
	return (ops);
}

static int	rotate_stack_b(t_stack **b, t_stack *cheap, t_bench *bench)
{
	int	ops;

	ops = 0;
	while (*b != cheap)
	{
		if (cheap->above_median)
		{
			bench_rb(bench);
			ops += rb(b);
		}
		else
		{
			bench_rrb(bench);
			ops += rrb(b);
		}
	}
	return (ops);
}

static int	rotate_stack_a(t_stack **a, t_stack *cheap, t_bench *bench)
{
	int	ops;

	ops = 0;
	while (*a != cheap->target_node)
	{
		if (cheap->target_node->above_median)
		{
			bench_ra(bench);
			ops += ra(a);
		}
		else
		{
			bench_rra(bench);
			ops += rra(a);
		}
	}
	return (ops);
}

int	finish_rotation(t_stack **a, t_stack **b, t_stack *cheap, t_bench *bench)
{
	int	ops;

	ops = 0;
	ops += rotate_stack_b(b, cheap, bench);
	ops += rotate_stack_a(a, cheap, bench);
	return (ops);
}
