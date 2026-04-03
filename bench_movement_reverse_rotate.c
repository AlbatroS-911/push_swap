/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_movement_reverse_rotate.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 06:58:23 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/03 07:57:22 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"

void	bench_rra(t_bench *bench)
{
	bench->rra++;
}

void	bench_rrb(t_bench *bench)
{
	bench->rrb++;
}

void	bench_rrr(t_bench *bench)
{
	bench->rrr++;
}
