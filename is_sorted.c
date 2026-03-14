/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:58:39 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/09 14:58:48 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	if (stack->size < 2)
		return (1);
	i = stack->size - 1;
	while (i > 0)
	{
		if (stack->data[i] < stack->data[i - 1])
			return (0);
		i--;
	}
	return (1);
}
