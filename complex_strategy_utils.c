/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_stategy_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:10:26 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/25 21:08:19 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "complex_strategy.h"

static void	sort_three(t_stack **stack)
{
	t_stack *max;
	
	max = find_max(*stack);
	if (max == *stack)
		ra(stack);
	else if ((*stack)->next == max)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);

}
void	init_push(t_stack **a, t_stack **b)
{
	int	size;
	int pushed;

	size = stack_size(*a);
	pushed = 0;
	while (size-- > 3)
	{
		pb(a, b);
		pushed++;
	}
	sort_three(a);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*a != cheap->target_node && *b != cheap)
		rr(a, b);
	set_above_median(*a);
	set_above_median(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*a != cheap->target_node && *b != cheap)
		rrr(a, b);
	set_above_median(*a);
	set_above_median(*b);
}

void	finish_rotation(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*b != cheap)
	{
		if (cheap->above_median)
			rb(b);
		else
			rrb(b);
	}
	while (*a != cheap->target_node)
	{
		if (cheap->target_node->above_median)
			ra(a);
		else
			rra(a);
	}
}
