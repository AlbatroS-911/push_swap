/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_movement_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 07:00:41 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/03 07:57:10 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"

void	bench_ra(t_bench *bench)
{
	bench->ra++;
}

void	bench_rb(t_bench *bench)
{
	bench->ra++;
}

void	bench_rr(t_bench *bench)
{
	bench->rr++;
}
