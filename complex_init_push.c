/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_init_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:09:35 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/08 16:17:49 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

static int	sort_three(t_stack **stack, t_bench *bench)
{
	t_stack	*max;
	int		ops;

	ops = 0;
	max = find_max(*stack);
	if (max == *stack)
	{
		bench_ra(bench);
		ops += ra(stack);
	}
	else if ((*stack)->next == max)
	{
		bench_rra(bench);
		ops += rra(stack);
	}
	if ((*stack)->value > (*stack)->next->value)
	{
		bench_sa(bench);
		ops += sa(stack);
	}
	return (ops);
}

int	init_push(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	pushed;
	int	ops;

	size = stack_size(*a);
	pushed = 0;
	ops = 0;
	while (size-- > 3)
	{
		bench_pb(bench);
		ops += pb(a, b);
		pushed++;
	}
	ops += sort_three(a, bench);
	return (ops);
}
