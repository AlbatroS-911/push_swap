/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_set_strategy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:33:26 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/26 08:47:56 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "complex_strategy.h"

t_stack *find_target(t_stack *a, int b_value)
{
	t_stack *target;
	t_stack *current;

	target = NULL;
	current = a;
	while (current)
	{
		if (current->value > b_value)
		{
			if (!target || current->value < target->value)
				target = current;
		}
		current = current->next;
	}
	if (!target)
		target = find_min(a);
	return (target);
}

void set_targets(t_stack *a, t_stack *b)
{
	while (b)
	{
		b->target_node = find_target(a, b->value);
		b = b->next;
	}
}

void	set_cheap_move(t_stack *b)
{
	t_stack	*current;
	t_stack	*cheapest;

	cheapest = b;
	current = b->next;
	while (current)
	{
		if (current->push_cost < cheapest->push_cost)
			cheapest = current;
		current = current->next;
	}
	current = b;
	while (current)
	{
		current->cheap_move = false;
		current = current->next;
	}
	cheapest->cheap_move = true;
}
void	set_above_median_both(t_stack *a, t_stack *b)
{
	set_above_median(a);
	set_above_median(b);
}
