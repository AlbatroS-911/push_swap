/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 21:35:35 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/09 08:19:47 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

void	finding_index(t_stack *stack)
{
	int		index;
	t_stack	*current_stack;
	t_stack	*reference_stack;

	current_stack = stack;
	while (current_stack)
	{
		reference_stack = stack;
		index = 0;
		while (reference_stack)
		{
			if (current_stack->value > reference_stack->value)
				index++;
			reference_stack = reference_stack->next;
		}
		current_stack->index = index;
		current_stack = current_stack->next;
	}
}

int	in_chunk(t_stack *node, int min, int max)
{
	return (node->index >= min && node->index <= max);
}

int	top_closer(t_stack **a, int min, int max)
{
	t_stack	*node;
	int		top_distance;
	int		bottom_distance;

	node = *a;
	top_distance = 0;
	while (node && !in_chunk(node, min, max))
	{
		top_distance++;
		node = node->next;
	}
	node = last_node(*a);
	bottom_distance = 0;
	while (node && !in_chunk(node, min, max))
	{
		bottom_distance++;
		node = node->prev;
	}
	return (top_distance <= bottom_distance);
}

static int	push_chunk_operation(t_stack **a, t_stack **b,
		t_intruction *instruct)
{
	int	ops;

	ops = 0;
	bench_pb(instruct->bench);
	ops += pb(a, b);
	if ((*b)->index > (instruct->min + instruct->max) / 2)
	{
		bench_rb(instruct->bench);
		ops += rb(b);
	}
	return (ops);
}

int	push_chunk(t_stack **a, t_stack **b, t_intruction *instruct)
{
	int	pushed;
	int	ops;

	pushed = 0;
	ops = 0;
	while (pushed < (instruct->max - instruct->min + 1) && *a)
	{
		if (in_chunk(*a, instruct->min, instruct->max))
		{
			ops += push_chunk_operation(a, b, instruct);
			pushed++;
		}
		else if (top_closer(a, instruct->min, instruct->max))
		{
			bench_ra(instruct->bench);
			ops += ra(a);
		}
		else
		{
			bench_rra(instruct->bench);
			ops += rra(a);
		}
	}
	return (ops);
}
