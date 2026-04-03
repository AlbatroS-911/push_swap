/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_strategy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 08:56:41 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/01 19:28:29 by tokrabem         ###   ########.fr       */
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

static int	execute_move(t_stack **a, t_stack **b)
{
	t_stack	*cheap;
	int		ops;

	ops = 0;
	cheap = get_cheap_node(*b);
	if (cheap->above_median && cheap->target_node->above_median)
		ops += rotate_both(a, b, cheap);
	else if (!cheap->above_median && !cheap->target_node->above_median)
		ops += rev_rotate_both(a, b, cheap);
	ops += finish_rotation(a, b, cheap);
	ops += pa(a, b);
	return (ops);
}
static int	finalize_sort(t_stack **a)
{
	t_stack	*min;
	int		ops;

	ops = 0;
	min = find_min(*a);
	set_above_median(*a);
	while (*a != min)
	{
		if (min->above_median)
			ops += ra(a);
		else
			ops += rra(a);
	}
	return (ops);
}
int	complex_strategy(t_stack **a, t_stack **b)
{
	int	total_ops;

	total_ops = 0;
	total_ops += init_push(a, b);
	while (*b)
	{
		set_above_median_both(*a, *b);
		set_targets(*a, *b);
		set_push_cost(*a, *b);
		set_cheap_move(*b);
		total_ops += execute_move(a, b);
	}
	total_ops += finalize_sort(a);
	return (total_ops);
}
