#include "push_swap.h"

float	compute_disorder(t_stack *a)
{
	t_stack	*current_i;
	t_stack	*current_j;
	float	mistakes;
	float	total_pairs;
	
	mistakes = 0;
	total_pairs = 0;
	current_i = a;
	if (!a || !a->next)
		return (0.0);
	while (current_i)
	{
		current_j = current_i->next;
		while (current_j)
		{
			total_pairs++;
			if (current_i->value > current_j->value)
				mistakes++;
			current_j = current_j->next;
		}
		current_i = current_i->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((float)mistakes / (float)total_pairs);
}
