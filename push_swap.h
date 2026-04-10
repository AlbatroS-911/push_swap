/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:47:56 by anjaraan          #+#    #+#             */
/*   Updated: 2026/04/09 16:34:25 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "bench.h"
# include "libft/libft.h"
# include "stdbool.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheap_move;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
}					t_stack;

typedef struct s_intruction
{
	t_bench			*bench;
	int				min;
	int				max;
}					t_intruction;

int					sa(t_stack **a);
int					sb(t_stack **b);
int					ss(t_stack **a, t_stack **b);
int					pa(t_stack **a, t_stack **b);
int					pb(t_stack **a, t_stack **b);
int					ra(t_stack **a);
int					rb(t_stack **b);
int					rr(t_stack **a, t_stack **b);
int					rra(t_stack **a);
int					rrb(t_stack **b);
int					rrr(t_stack **a, t_stack **b);
int					is_sorted(t_stack *stack);
void				show_bench(t_stack **a, t_stack **b, char *flag);
void				adaptive_strategy(t_stack **a, t_stack **b);
int					simple_strategy(t_stack **a, t_stack **b, t_bench *bench);
int					medium_strategy(t_stack **a, t_stack **b, t_bench *bench);
int					complex_strategy(t_stack **a, t_stack **b, t_bench *bench);
int					ft_printf(const char *format, ...);
float				compute_disorder(t_stack *a);
t_stack				*last_node(t_stack *a);
t_stack				*find_min(t_stack *stack);
t_stack				*find_max(t_stack *stack);
t_stack				*new_node(int value);
int					stack_size(t_stack *stack);
void				set_above_median(t_stack *stack);
float				ft_sqrt(int number);
void				add_back(t_stack **stack, t_stack *new);
void				print_stack(t_stack *stack);

#endif