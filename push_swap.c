#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->push_cost = 0;
	node->above_median = false;
	node->cheap_move = false;
	node->target_node = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;

}


void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	*a;
	t_stack *b;

	a = NULL;
	b = NULL;

	add_back(&a, new_node(100));
	add_back(&a, new_node(2));
	add_back(&a, new_node(1));
	add_back(&a, new_node(30));
	add_back(&a, new_node(3));
	add_back(&a, new_node(5));
	add_back(&a, new_node(4));
	add_back(&a, new_node(32));

	printf("Avant:\n");
	print_stack(a);

	ft_printf("Disorder metric = %f\n", compute_disorder(a));

	// ra(&a);
	// sa(&a);

	printf("Apres:\n");
	simple_strategy(&a, &b);
	print_stack(a);

	return (0);
}