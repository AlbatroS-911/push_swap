/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:52:26 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/09 12:49:12 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	a->data[a->size] = b->data[b->size - 1];
	a->size++;
	b->size--;
	// ft_putstr("pa\n");
}
