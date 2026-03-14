/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:47:00 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/09 12:49:34 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *b)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->data[b->size - 1];
	b->data[b->size - 1] = b->data[b->size - 2];
	b->data[b->size - 2] = temp;
	// ft_putstr("sb\n");
}
