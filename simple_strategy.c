/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:46:55 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/09 11:38:26 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_strategy(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
		return ;
	}
	if (a->size == 3)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
		if (a->top->next->value > a->top->next->next->value)
			rra(a);
		if (a->top->value > a->top->next->value)
			sa(a);
		return ;
	}
	while (a->size > 3)
		pb(a, b);
	simple_strategy(a, b);
	while (b->size > 0)
		pa(a, b);
}
