/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_strategy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:04:03 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/02 21:31:08 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_strategy(t_stack **a, t_stack **b)
{
	float	disorder_index;

	disorder_index = compute_disorder(*a);
	ft_printf("Disorder :%f\n", disorder_index);
	if (disorder_index < 0.2)
	{
		ft_printf("Total operations : %d\n", simple_strategy(a, b));
		ft_printf("Adaptive / O(n²)\n");
	}
	else if (disorder_index >= 0.2 && disorder_index < 0.5)
	{
		ft_printf("Total operations : %d\n", medium_strategy(a, b));
		ft_printf("Adaptive / O(n√n)\n");
	}
	else
	{
		ft_printf("Total operations : %d\n", complex_strategy(a, b));
		ft_printf("Adaptive / O(n log n)\n");
	}
}
