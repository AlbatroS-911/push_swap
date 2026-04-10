/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_movement_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 07:00:41 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/09 22:28:52 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

void	bench_ra(t_bench *bench)
{
	bench->ra++;
	if (bench->print_moves)
		ft_putstr_fd("ra\n", 1);
}

void	bench_rb(t_bench *bench)
{
	bench->rb++;
	if (bench->print_moves)
		ft_putstr_fd("rb\n", 1);
}

void	bench_rr(t_bench *bench)
{
	bench->rr++;
	if (bench->print_moves)
		ft_putstr_fd("rr\n", 1);
}
