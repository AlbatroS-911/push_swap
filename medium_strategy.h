/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:41:53 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/23 16:47:49 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEDIUM_STRATEGY_H
# define MEDIUM_STRATEGY_H

# include "push_swap.h"

void	finding_index(t_stack *stack);
int		in_chunk(t_stack *node, int max, int min);
int		top_closer(t_stack **a, int min, int max);
void	push_chunk(t_stack **a, t_stack **b, int min, int max);

#endif