/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:48:24 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/07 19:25:56 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **to, t_stack **from)
{
	t_stack	*temp_node;

	if (!*from)
		return ;
	temp_node = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	temp_node->prev = NULL;
	if (!*to)
	{
		*to = temp_node;
		temp_node->next = NULL;
	}
	else
	{
		temp_node->next = *to;
		(*to)->prev = temp_node;
		*to = temp_node;
	}
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	return (1);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	return (1);
}
