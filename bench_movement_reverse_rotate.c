/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_movement_reverse_rotate.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 06:58:23 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/05 22:30:48 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"
#include "push_swap.h"

void	bench_rra(t_bench *bench)
{
	bench->rra++;
	if (bench->print_moves)
		ft_printf("rra\n");
}

void	bench_rrb(t_bench *bench)
{
	bench->rrb++;
	if (bench->print_moves)
		ft_printf("rrb\n");
	
}

void	bench_rrr(t_bench *bench)
{
	bench->rrr++;
	if (bench->print_moves)
		ft_printf("rrr\n");
}
