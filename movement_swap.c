#include "push_swap.h"

static void swap(t_stack **head)
{
	t_stack *first;
	t_stack *second;
	
	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
	
}

int	sa(t_stack **a)
{
	swap(a);
	return (1);
}

int	sb(t_stack **b)
{
	swap(b);
	return (1);
}

int	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	return (1);
}
