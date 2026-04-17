/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_print_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:05:44 by anjaraan          #+#    #+#             */
/*   Updated: 2026/04/17 15:31:55 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_error(t_stack **stack)
{
	write(2, "Error\n", 6);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
