/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_movement_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 07:00:41 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/05 22:30:54 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

void	bench_ra(t_bench *bench)
{
	bench->ra++;
	if (bench->print_moves)
		ft_printf("ra\n");
}

void	bench_rb(t_bench *bench)
{
	bench->rb++;
	if (bench->print_moves)
		ft_printf("rb\n");
}

void	bench_rr(t_bench *bench)
{
	bench->rr++;
	if (bench->print_moves)
		ft_printf("rr\n");
}
