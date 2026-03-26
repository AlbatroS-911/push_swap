/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_strategy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:04:03 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/25 21:17:04 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_strategy(t_stack **a, t_stack **b)
{
	float	disorder_index;

	disorder_index = compute_disorder(*a);
	if (disorder_index < 0.2)
	{
		simple_strategy(a, b);
		ft_printf("Strategy used: Simple\n");
	}
	else if (disorder_index >= 0.2 && disorder_index < 0.5)
	{
		medium_strategy(a, b);
		ft_printf("Strategy used: Medium\n");
	}
	else
	{
		complex_strategy(a, b);
		ft_printf("Strategy used: Complex\n");
	}
}
