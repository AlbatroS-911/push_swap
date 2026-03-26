/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:46:55 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/23 15:54:30 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_strategy.h"

static void	bring_to_top(t_stack **stack, t_stack *target)
{
	while (*stack != target)
	{
		if (target->above_median)
			ra(stack);
		else
			rra(stack);
	}
}

static void	sort_two(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

static void	sort_three(t_stack **stack)
{
	t_stack *max;
	
	max = find_max(*stack);
	if (max == *stack)
		ra(stack);
	else if ((*stack)->next == max)
		rra(stack);
	sort_two(stack);
}

void	simple_strategy(t_stack **a, t_stack **b)
{
	t_stack *min;
	int 	size;

	size = stack_size(*a);
	while (size-- > 3)
	{
		set_above_median(*a);
		min = find_min(*a);
		bring_to_top(a, min);
		pb(a, b);
	}
	sort_three(a);
	while(*b)
		pa(a, b);
}
