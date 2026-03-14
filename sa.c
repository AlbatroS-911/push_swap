/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:38:46 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/09 12:49:44 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->data[a->size - 1];
	a->data[a->size - 1] = a->data[a->size - 2];
	a->data[a->size - 2] = temp;
	// ft_putstr("sa\n");
}
