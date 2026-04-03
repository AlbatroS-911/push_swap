/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:46:55 by anjaraan          #+#    #+#             */
/*   Updated: 2026/04/02 21:40:04 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_strategy.h"

static int	bring_to_top(t_stack **stack, t_stack *target)
{
	int	ops;

	ops = 0;
	while (*stack != target)
	{
		if (target->above_median)
			ops += ra(stack);
		else
			ops += rra(stack);
	}
	return (ops);
}

static int	sort_two(t_stack **stack)
{
	int	ops;

	ops = 0;
	if ((*stack)->value > (*stack)->next->value)
		ops += sa(stack);
	return (ops);
}

static int	sort_three(t_stack **stack)
{
	t_stack	*max;
	int		ops;

	ops = 0;
	max = find_max(*stack);
	if (max == *stack)
		ops += ra(stack);
	else if ((*stack)->next == max)
		ops += rra(stack);
	ops += sort_two(stack);
	return (ops);
}

int	simple_strategy(t_stack **a, t_stack **b)
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
		total_ops += bring_to_top(a, min);
		total_ops += pb(a, b);
	}
	total_ops += sort_three(a);
	while (*b)
		total_ops += pa(a, b);
	ft_printf("Total : %d\n", total_ops);
	return (total_ops);
}
