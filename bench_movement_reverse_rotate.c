/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_movement_reverse_rotate.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 06:58:23 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/08 09:39:31 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

void	bench_rra(t_bench *bench)
{
	bench->rra++;
	if (bench->print_moves)
		ft_putstr_fd("rra\n", 1);
}

void	bench_rrb(t_bench *bench)
{
	bench->rrb++;
	if (bench->print_moves)
		ft_putstr_fd("rrb\n", 1);
}

void	bench_rrr(t_bench *bench)
{
	bench->rrr++;
	if (bench->print_moves)
		ft_putstr_fd("rrr\n", 1);
}
