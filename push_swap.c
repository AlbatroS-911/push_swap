/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:50:47 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/09 08:19:35 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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
	return (0);
}
