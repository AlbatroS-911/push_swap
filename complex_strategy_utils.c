/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_strategy_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:10:26 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/04 16:47:23 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "complex_strategy.h"
#include "bench.h"

static int	sort_three(t_stack **stack, t_bench *bench)
{
	t_stack *max;
	int		ops;
	
	ops = 0;
	max = find_max(*stack);
	if (max == *stack)
	{
		bench_ra(bench);
		ops += ra(stack);
	}
	else if ((*stack)->next == max)
	{
		bench_rra(bench);
		ops += rra(stack);
	}
	if ((*stack)->value > (*stack)->next->value)
	{
		bench_sa(bench);
		ops += sa(stack);
	}
	return (ops);

}

int	init_push(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int pushed;
	int	ops;

	size = stack_size(*a);
	pushed = 0;
	ops = 0;
	while (size-- > 3)
	{
		bench_pb(bench);
		ops += pb(a, b);
		pushed++;
	}
	ops += sort_three(a, bench);
	return (ops);
}

int	rotate_both(t_stack **a, t_stack **b, t_stack *cheap, t_bench *bench)
{
	int ops;

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

int	finish_rotation(t_stack **a, t_stack **b, t_stack *cheap, t_bench *bench)
{
	int ops;

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
