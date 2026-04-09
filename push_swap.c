/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:50:47 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/09 11:38:16 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench *bench;
	char *flag = NULL;
	char *ben = NULL;

	a = NULL;
	b = NULL;
	bench = malloc(sizeof(t_bench));
	bench->print_moves = 1;
	if (argc < 2)
		return (0);
	parse_all_input(argc, argv, &a, &flag, &ben);
	ft_printf("%s\n%s\n", flag, ben);
	if (!check_bench_flag(ben))
	{
		if (check_flag(flag) == 2)
			simple_strategy(&a, &b, bench);
		if (check_flag(flag) == 1)
			medium_strategy(&a, &b, bench);
		if (check_flag(flag) == 3)
			complex_strategy(&a, &b, bench);
		if (check_flag(flag) == 4 || !(check_flag(flag)))
			adaptive_strategy(&a, &b);
	}
	else
	{
		show_bench(&a, &b);
	}
	return (0);
}
