/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 06:44:21 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/05 22:23:17 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCH_H
# define BENCH_H

typedef struct s_bench
{
	int	pa;
	int	pb;
	int	rra;
	int	rrb;
	int	rrr;
	int	ra;
	int	rb;
	int	rr;
	int	sa;
	int	sb;
	int	ss;
	int	print_moves;
}		t_bench;

void	bench_pa(t_bench *bench);
void	bench_pb(t_bench *bench);
void	bench_rra(t_bench *bench);
void	bench_rrb(t_bench *bench);
void	bench_rrr(t_bench *bench);
void	bench_ra(t_bench *bench);
void	bench_rb(t_bench *bench);
void	bench_rr(t_bench *bench);
void	bench_sa(t_bench *bench);
void	bench_sb(t_bench *bench);
void	bench_ss(t_bench *bench);

#endif