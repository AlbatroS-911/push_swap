/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:46:55 by anjaraan          #+#    #+#             */
/*   Updated: 2026/04/04 16:41:07 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "simple_strategy.h"

static int	bring_to_top(t_stack **stack, t_bench *bench, t_stack *target)
{
	int	ops;

	ops = 0;
	while (*stack != target)
	{
		if (target->above_median)
		{
			bench_ra(bench);
			ops += ra(stack);
		}
		else
		{
			bench_rra(bench);
			ops += rra(stack);
		}
	}
	return (ops);
}

static int	sort_two(t_stack **stack, t_bench *bench)
{
	int	ops;

	ops = 0;
	if ((*stack)->value > (*stack)->next->value)
	{
		bench_sa(bench);
		ops += sa(stack);
	}
	return (ops);
}

static int	sort_three(t_stack **stack, t_bench *bench)
{
	t_stack	*max;
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
	ops += sort_two(stack, bench);
	return (ops);
}

int	simple_strategy(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*min;
	int		size;
	int		total_ops;

	size = stack_size(*a);
	total_ops = 0;
	while (size-- > 3)
	{
		set_above_median(*a);
		min = find_min(*a);
		total_ops += bring_to_top(a, bench, min);
		bench_pb(bench);
		total_ops += pb(a, b);
	}
	total_ops += sort_three(a, bench);
	while (*b)
	{
		bench_pa(bench);
		total_ops += pa(a, b);
	}
	return (total_ops);
}
