/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_strategy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:27:31 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/05 22:29:59 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_strategy(t_stack **a, t_stack **b)
{
	float	disorder_index;
	t_bench *bench;
	
	disorder_index = compute_disorder(*a);
	bench = malloc(sizeof(t_bench));
	bench->print_moves = 1;
	if (disorder_index < 0.2)
		(void)simple_strategy(a, b, bench);
	else if (disorder_index >= 0.2 && disorder_index < 0.5)
		(void)medium_strategy(a, b, bench);
	else
		(void)complex_strategy(a, b, bench);
	free(bench);
}
