/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_set_cost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:05:33 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/25 21:08:39 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "complex_strategy.h"

int	cost_to_top(t_stack *stack, t_stack *target)
{
	int	cost;
	int	size;

	cost = 0;
	size = stack_size(stack);
	while (stack != target)
	{
		cost++;
		stack = stack->next;
	}
	if (cost > size / 2)
		cost = size - cost;
	return (cost);
}

void	set_push_cost(t_stack *a, t_stack *b)
{
	t_stack	*current;
	int		cost_b;
	int		cost_a;

	current = b;
	while (current)
	{
		cost_b = cost_to_top(b, current);
		cost_a = cost_to_top(a, current->target_node);
		if (current->above_median && current->target_node->above_median)
			current->push_cost = (cost_b > cost_a ? cost_b : cost_a);
		else if (!current->above_median && !current->target_node->above_median)
			current->push_cost = (cost_b > cost_a ? cost_b : cost_a);
		else
			current->push_cost = cost_b + cost_a; 
		current->push_cost++;
		current = current->next;
	}
}
