/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_above_median.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:52:55 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/23 15:54:21 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_above_median(t_stack *stack)
{
	int	size;
	int	median;
	int	i;

	size = stack_size(stack);
	median = size / 2;
	i = 0;
	while (stack)
	{
		stack->above_median = (i <= median);
		i++;
		stack = stack->next;
	}
}
