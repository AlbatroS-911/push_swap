#include "push_swap.h"

static void	push(t_stack **to, t_stack **from)
{
	t_stack *temp_node; // to store the node to be pushed

	if (!*from)
		return ;
	temp_node = *from;
	*from = (*from)->next; // Move the head of the from stack to the next node
	if (*from)
		(*from)->prev = NULL;
	temp_node->prev = NULL;
	if (!*to)
	{
		*to = temp_node; //Set the temp as the first node if dest is empty
		temp_node->next = NULL;
	}
	else // if it's not empty, add temp at the top of dest
	{
		temp_node->next = *to;
		(*to)->prev = temp_node;
		*to = temp_node;
	}
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}
void pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}

