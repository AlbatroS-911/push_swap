/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_strategy_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:10:26 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/01 18:59:32 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "complex_strategy.h"

static int	sort_three(t_stack **stack)
{
	t_stack *max;
	int		ops;
	
	ops = 0;
	max = find_max(*stack);
	if (max == *stack)
		ops += ra(stack);
	else if ((*stack)->next == max)
		ops += rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		ops += sa(stack);
	return (ops);

}
int	init_push(t_stack **a, t_stack **b)
{
	int	size;
	int pushed;
	int	ops;

	size = stack_size(*a);
	pushed = 0;
	ops = 0;
	while (size-- > 3)
	{
		ops += pb(a, b);
		pushed++;
	}
	ops += sort_three(a);
	return (ops);
}

int	rotate_both(t_stack **a, t_stack **b, t_stack *cheap)
{
	int ops;

	ops = 0;
	while (*a != cheap->target_node && *b != cheap)
		ops += rr(a, b);
	set_above_median(*a);
	set_above_median(*b);
	return (ops);
}

int	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheap)
{
	int	ops;

	ops = 0;
	while (*a != cheap->target_node && *b != cheap)
		ops += rrr(a, b);
	set_above_median(*a);
	set_above_median(*b);
	return (ops);
}

int	finish_rotation(t_stack **a, t_stack **b, t_stack *cheap)
{
	int ops;

	ops = 0;
	while (*b != cheap)
	{
		if (cheap->above_median)
			ops += rb(b);
		else
			ops += rrb(b);
	}
	while (*a != cheap->target_node)
	{
		if (cheap->target_node->above_median)
			ops += ra(a);
		else
			ops += rra(a);
	}
	return (ops);
}
