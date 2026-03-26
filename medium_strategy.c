/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 11:28:20 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/24 20:28:19 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "medium_strategy.h"

static void bring_b_to_top(t_stack **b, t_stack *target)
{
	while (*b != target)
	{
		if (target->above_median)
			rb(b);
		else
			rrb(b);
	}
}

static void	pull_back(t_stack **a, t_stack **b)
{
	t_stack	*max;

	while (*b)
	{
		set_above_median(*b);
		max = find_max(*b);
		bring_b_to_top(b, max);
		pa(a, b);
	}
}

void	medium_strategy(t_stack **a, t_stack **b)
{	
	int	size;
	int	chunk_size;
	int	chunk;
	int	min;
	int	max;

	finding_index(*a);
	size = stack_size(*a);
	chunk_size = (int)ft_sqrt((double)size);
	chunk = 0;
	while (chunk * chunk_size < size)
	{
		min = chunk * chunk_size;
		max = min + chunk_size - 1;
		if (max >= size)
			max = size - 1;
		push_chunk(a, b, min, max);
		chunk++;
	}
	pull_back(a, b);
}
