/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:28:20 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/16 23:43:43 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "medium_strategy.h"

static int	bring_b_to_top(t_stack **b, t_bench *bench, t_stack *target)
{
	int	ops;

	ops = 0;
	while (*b != target)
	{
		if (target->above_median)
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

static int	pull_back(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*max;
	int		ops;

	ops = 0;
	while (*b)
	{
		set_above_median(*b);
		max = find_max(*b);
		ops += bring_b_to_top(b, bench, max);
		bench_pa(bench);
		ops += pa(a, b);
	}
	return (ops);
}

static int	small_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*min;
	int		ops;

	ops = 0;
	while (*a && !is_sorted(*a))
	{
		set_above_median(*a);
		min = find_min(*a);
		while (*a != min)
		{
			if (min->above_median)
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
		bench_pb(bench);
		ops += pb(a, b);
	}
	return (ops + pull_back(a, b, bench));
}

static int	main_medium_operation(t_stack **a, t_stack **b, int size,
		t_bench *bench)
{
	t_intruction	*instruct;
	int				chunk;
	int				ops;

	chunk = 0;
	ops = 0;
	instruct = malloc(sizeof(t_intruction));
	if (!instruct)
		return (0);
	instruct->bench = bench;
	while (chunk * (int)ft_sqrt((double)size) < size && !is_sorted(*a))
	{
		instruct->min = chunk * (int)ft_sqrt((double)size);
		instruct->max = instruct->min + (int)ft_sqrt((double)size) - 1;
		if (instruct->max >= size)
			instruct->max = size - 1;
		ops += push_chunk(a, b, instruct);
		chunk++;
	}
	free(instruct);
	return (ops);
}

int	medium_strategy(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	total_ops;

	finding_index(*a);
	size = stack_size(*a);
	total_ops = 0;
	if (size <= 25)
		total_ops += small_sort(a, b, bench);
	else
	{
		total_ops += main_medium_operation(a, b, size, bench);
		total_ops += pull_back(a, b, bench);
	}
	return (total_ops);
}
