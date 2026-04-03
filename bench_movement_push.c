/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_movement_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 06:44:04 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/03 07:57:36 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"

void	bench_pa(t_bench *bench)
{
	bench->pa++;
}

void	bench_pb(t_bench *bench)
{
	bench->pb++;
}
