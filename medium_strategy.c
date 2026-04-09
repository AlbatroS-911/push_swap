/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:28:20 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/08 19:54:07 by tokrabem         ###   ########.fr       */
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

int	medium_strategy(t_stack **a, t_stack **b, t_bench *bench)
{
	int				size;
	int				chunk;
	t_intruction	*instruct;
	int				total_ops;

	finding_index(*a);
	size = stack_size(*a);
	chunk = 0;
	total_ops = 0;
	instruct = malloc(sizeof(t_intruction));
	if (!instruct)
		return (0);
	instruct->bench = bench;
	while (chunk * (int)ft_sqrt((double)size) < size)
	{
		instruct->min = chunk * (int)ft_sqrt((double)size);
		instruct->max = instruct->min + (int)ft_sqrt((double)size) - 1;
		if (instruct->max >= size)
			instruct->max = size - 1;
		total_ops += push_chunk(a, b, instruct);
		chunk++;
	}
	total_ops += pull_back(a, b, bench);
	free(instruct);
	return (total_ops);
}
