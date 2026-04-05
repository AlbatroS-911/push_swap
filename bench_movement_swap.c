/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_movement_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 07:02:36 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/05 22:31:00 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

void	bench_sa(t_bench *bench)
{
	bench->sa++;
	if (bench->print_moves)
		ft_printf("sa\n");
}

void	bench_sb(t_bench *bench)
{
	bench->sb++;
	if (bench->print_moves)
		ft_printf("sb\n");
}

void	bench_ss(t_bench *bench)
{
	bench->ss++;
	if (bench->print_moves)
		ft_printf("ss\n");
}
