/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_print_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:05:44 by anjaraan          #+#    #+#             */
/*   Updated: 2026/04/21 11:44:34 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_error(t_stack **stack, t_error *error)
{
	write(1, "Error\n", 6);
	free_stack(stack);
	if (error)
	{
		free(error->bench);
		free(error->flag_bench);
		free(error);
	}
	exit(EXIT_FAILURE);
}
