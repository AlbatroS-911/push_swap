/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:52:48 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/09 12:49:20 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return ;
	b->data[b->size] = a->data[a->size - 1];
	b->size++;
	a->size--;
	// ft_putstr("pb\n");
}
