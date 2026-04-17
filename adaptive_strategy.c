/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_strategy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjaraan <anjaraan@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:27:31 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/11 11:09:35 by anjaraan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_strategy(t_stack **a, t_stack **b)
{
	float	disorder_index;
	t_bench	*bench;
	int		total_ops;

	disorder_index = compute_disorder(*a);
	bench = malloc(sizeof(t_bench));
	bench->print_moves = 1;
	total_ops = 0;
	if (disorder_index == 0)
	{
		free(bench);
		return ;
	}
	else if (disorder_index < 0.2)
		simple_strategy(a, b, bench);
	else if (disorder_index >= 0.2 && disorder_index < 0.5)
		medium_strategy(a, b, bench);
	else
		complex_strategy(a, b, bench);
	free(bench);
}
