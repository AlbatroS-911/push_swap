/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_bench.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:26:26 by anjaraan          #+#    #+#             */
/*   Updated: 2026/04/09 10:29:27 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_bench_flag(const char *str)
{
	if ((ft_strcmp(str, "--bench") == 0))
		return (1);
	return (0);
}

int	is_bench(const char *str)
{
	return (check_bench_flag(str) != 0);
}

int	check_duplicate_bench_flag(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		if (is_bench(argv[i]))
		{
			j = i + 1;
			while (j < argc)
			{
				if (is_bench(argv[j]))
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}

int	check_bench_flag_position(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_bench(argv[i]))
		{
			if (check_strat_flag_presence(argc, argv))
			{
				if (i != 1 && i != 2 && i != argc - 1 && i != argc - 2)
					return (0);
			}
			else if (i != 1 && i != argc - 1)
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	check_strat_flag_presence(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
