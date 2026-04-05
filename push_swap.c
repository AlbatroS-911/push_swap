#include <stdlib.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		value;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		add_back(&a, new_node(value));
		i++;
	}
	// adaptive_strategy(&a, &b);
	show_bench(&a, &b);
	i = 1;
	while (i < argc)
	{
		free(last_node(a));
		i++;
	}
	return (0);
}
