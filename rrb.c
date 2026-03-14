/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:11:03 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/09 13:11:22 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack *b)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->data[0];
	ft_memmove(b->data, b->data + 1, sizeof(int) * (b->size - 1));
	b->data[b->size - 1] = temp;
	// ft_putstr("rrb\n");
	// ft_putstr("rrb\n");
}
