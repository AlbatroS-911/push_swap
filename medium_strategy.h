/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:41:53 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/08 19:28:54 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEDIUM_STRATEGY_H
# define MEDIUM_STRATEGY_H

# include "bench.h"
# include "push_swap.h"

void	finding_index(t_stack *stack);
int		in_chunk(t_stack *node, int max, int min);
int		top_closer(t_stack **a, int min, int max);
int		push_chunk(t_stack **a, t_stack **b, t_intruction *instruct);

#endif