#include "push_swap.h"

static void reverse_rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = last_node(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
}
int	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
	return (1);
}

int	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
	return (1);
}