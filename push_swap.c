#include <stdlib.h>
#include "push_swap.h"
#include "libft/libft.h"
// #include "ft_printf/ft_printf.h"

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
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		value;
	// float	disorder_metric;

	a = NULL;
	b = NULL;
	// disorder_metric = 0;

	if (argc < 2)
		return (0);

	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		add_back(&a, new_node(value));
		i++;
	}
	// disorder_metric = compute_disorder(a) * 100;
	// ft_printf("Before:\n");
	// print_stack(a);
	// ft_printf("Operations:\n");
	// adaptive_strategy(&a, &b);
	// ft_printf("After:\n");
	// print_stack(a);
	show_bench(&a, &b);
	// ft_printf("Disorder metric = %f%%\n", disorder_metric);

	return (0);
}
