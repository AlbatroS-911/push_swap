/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_movement_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 06:44:04 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/09 22:28:30 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

void	bench_pa(t_bench *bench)
{
	bench->pa++;
	if (bench->print_moves)
		ft_putstr_fd("pa\n", 1);
}

void	bench_pb(t_bench *bench)
{
	bench->pb++;
	if (bench->print_moves)
		ft_putstr_fd("pb\n", 1);
}
