/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:55:45 by anjaraan          #+#    #+#             */
/*   Updated: 2026/04/09 10:29:43 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "push_swap.h"

int	check_flag(const char *str)
{
	if (ft_strcmp(str, "--simple") == 0)
		return (1);
	else if (ft_strcmp(str, "--medium") == 0)
		return (2);
	else if (ft_strcmp(str, "--complex") == 0)
		return (3);
	else if (ft_strcmp(str, "--adaptive") == 0)
		return (4);
	else
		return (0);
}

int	is_flag(const char *str)
{
	return (check_flag(str) != 0);
}

int	check_duplicate_flag(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		if (is_flag(argv[i]))
		{
			j = i + 1;
			while (j < argc)
			{
				if (is_flag(argv[j]))
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}

int	check_flag_position(int argc, char **argv)
{
	int	i;
	int	f;

	i = 0;
	while (++i < argc)
	{
		f = (is_flag(argv[i]) || is_bench(argv[i]));
		if (f)
		{
			if (i == 1 || i == argc - 1)
				continue ;
			if (i == 2 && (is_flag(argv[1]) || is_bench(argv[1])))
				continue ;
			if (i == argc - 2 && (is_flag(argv[argc - 1])
					|| is_bench(argv[argc - 1])))
				continue ;
			return (0);
		}
	}
	return (1);
}

int	check_flag_bench_presence(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_bench(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
