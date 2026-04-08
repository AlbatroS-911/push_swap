/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_strategy.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:10:43 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/07 18:51:53 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_STRATEGY_H
# define COMPLEX_STRATEGY_H

# include "bench.h"
# include "push_swap.h"

int		init_push(t_stack **a, t_stack **b, t_bench *bench);
int		rotate_both(t_stack **a, t_stack **b, t_stack *cheap, t_bench *bench);
int		rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheap,
			t_bench *bench);
int		finish_rotation(t_stack **a, t_stack **b, t_stack *cheap,
			t_bench *bench);
t_stack	*find_target(t_stack *a, int b_value);
void	set_targets(t_stack *a, t_stack *b);
void	set_cheap_move(t_stack *b);
void	set_above_median_both(t_stack *a, t_stack *b);
int		cost_to_top(t_stack *stack, t_stack *target);
void	set_push_cost(t_stack *a, t_stack *b);

#endif