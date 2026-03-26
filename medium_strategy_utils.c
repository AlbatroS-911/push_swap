/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 21:35:35 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/24 20:27:04 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finding_index(t_stack *stack)
{
	int index;
	t_stack *current_stack;
	t_stack *reference_stack;

	current_stack = stack;
	while (current_stack)
	{
		reference_stack = stack;
		index = 0;
		while(reference_stack)
		{
			if (current_stack->value > reference_stack->value)
				index++;
			reference_stack = reference_stack->next;
		}
		current_stack->index = index;
		current_stack = current_stack->next;
	}
}

int in_chunk(t_stack *node, int min, int max)
{
	return (node->index >= min && node->index <= max);
}

int	top_closer(t_stack **a, int min, int max)
{
	t_stack *node;
	int	top_distance;
	int	bottom_distance;

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

void	push_chunk(t_stack **a, t_stack **b, int min, int max)
{
	int	pushed;
	int	chunk_count;

	chunk_count = max - min + 1;
	pushed = 0;
	while (pushed < chunk_count && *a)
	{
		if (in_chunk(*a, min, max))
		{
			pb(a, b);
			if ((*b)->index > (min + max) / 2)
				rb(b);
			pushed++;
		}
		else if (top_closer(a, min, max))
			ra(a);
		else
			rra(a);
	}
}
