#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

// 🔧 fonction utilitaire pour créer un node propre
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

// 🔧 fonction pour ajouter à la fin
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

// 🔧 fonction pour afficher la stack
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

	a = NULL;

	// 🔥 Initialisation avec 5 valeurs
	add_back(&a, new_node(5));
	add_back(&a, new_node(4));
	add_back(&a, new_node(3));
	add_back(&a, new_node(2));
	add_back(&a, new_node(1));

	// 🔍 Affichage initial
	printf("Avant:\n");
	print_stack(a);

	ft_printf("Disorder metric = %f ", compute_disorder(a));
	// 👉 TEST ICI (remplace par ta fonction)
	// ex: rotate(&a);
	// ex: swap(&a);
	// ex: push(&b, &a);

	printf("Apres:\n");
	print_stack(a);

	return (0);
}