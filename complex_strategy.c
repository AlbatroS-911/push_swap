/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_strategy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 08:56:41 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/25 20:59:17 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex_strategy.h"

static t_stack	*get_cheap_node(t_stack *b)
{
	while (b)
	{
		if (b->cheap_move)
			return (b);
		b = b->next;
	}
	return (NULL);
}

static void	execute_move(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = get_cheap_node(*b);
	if (cheap->above_median && cheap->target_node->above_median)
		rotate_both(a, b, cheap);
	else if (!cheap->above_median && !cheap->target_node->above_median)
		rev_rotate_both(a, b, cheap);
	finish_rotation(a, b, cheap);
	pa(a, b);
}
static void	finalize_sort(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a);
	set_above_median(*a);
	while (*a != min)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}
}
void complex_strategy(t_stack **a, t_stack **b)
{
	init_push(a, b);
	while (*b)
	{
		set_above_median_both(*a, *b);
		set_targets(*a, *b);
		set_push_cost(*a, *b);
		set_cheap_move(*b);
		execute_move(a, b);
	}
	finalize_sort(a);
}
