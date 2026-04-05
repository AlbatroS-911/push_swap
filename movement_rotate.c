#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = last_node(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

int	ra(t_stack **a)
{
	rotate(a);
	return (1);
}

int	rb(t_stack **b)
{
	rotate(b);
	return (1);
}

int	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	return (1);
}
