/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 21:35:35 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/21 09:56:20 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finding_index(t_stack *stack)
{
	int index;
	t_stack *current_stack;
	t_stack *reference_stack;

	current_stack = stack;
	while (current_stack)
	{
		reference_stack = stack;
		index = 0;
		while(reference_stack)
		{
			if (current_stack->value > reference_stack->value)
				index++;
			reference_stack = reference_stack->next;
		}
		current_stack->index = index;
		current_stack = current_stack->next;
	}
}

float	ft_sqrt(int number)
{
	double	i;
	
	i = 0.01;
	while (i * i <= number)
	{
		if (i * i == number)
			return(i);
		i = i + 0.01;
	}
	return (i);
}
