/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_strategy_radix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 06:32:39 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/18 06:43:18 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "medium_strategy.h"

static int	get_max_bits(int size)
{
	int	bits;
	int	max;

	bits = 0;
	max = size - 1;
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

static int	bit_varies(t_stack *a, int bit)
{
	int	first;

	first = (a->index >> bit) & 1;
	while (a)
	{
		if (((a->index >> bit) & 1) != first)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	radix_pass(t_stack **a, t_stack **b,
		t_bench *bench, int bit)
{
	int	ops;
	int	size;
	int	i;

	ops = 0;
	size = stack_size(*a);
	i = 0;
	while (i++ < size)
	{
		if (((*a)->index >> bit) & 1)
		{bench_ra(bench); ops += ra(a);}
		else
		{bench_pb(bench); ops += pb(a, b);}
	}
	while (*b)
	{bench_pa(bench); ops += pa(a, b);}
	return (ops);
}

int	complex_strategy_radix(t_stack **a, t_stack **b, t_bench *bench)
{
	int	bits;
	int	bit;
	int	total_ops;

	if (is_sorted(*a))
		return (0);
	finding_index(*a);
	bits = get_max_bits(stack_size(*a));
	bit = 0;
	total_ops = 0;
	while (bit < bits)
	{
		if (bit_varies(*a, bit))
			total_ops += radix_pass(a, b, bench, bit);
		bit++;
	}
	return (total_ops);
}