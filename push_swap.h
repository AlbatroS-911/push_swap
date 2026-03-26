/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:47:56 by anjaraan          #+#    #+#             */
/*   Updated: 2026/03/25 21:10:25 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "stdbool.h"

// Data structures for stacks and nodes 
typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool 			cheap_move;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
}	t_stack	;

// All the different stack operations

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
int		is_sorted(t_stack *stack);
void	adaptive_strategy(t_stack **a, t_stack **b);
void	simple_strategy(t_stack **a, t_stack **b);
void	medium_strategy(t_stack **a, t_stack **b);
void	complex_strategy(t_stack **a, t_stack **b);
int		ft_printf(const char *format, ...);
float	compute_disorder(t_stack *a);
t_stack	*last_node(t_stack *a);
t_stack	*find_min(t_stack *stack);
t_stack *find_max(t_stack *stack);
int		stack_size(t_stack *stack);
void	set_above_median(t_stack *stack);
float	ft_sqrt(int number);

#endif