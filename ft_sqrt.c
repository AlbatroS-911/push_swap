/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 16:19:34 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/07 18:52:10 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_sqrt(int number)
{
	double	i;

	i = 0.01;
	while (i * i <= number)
	{
		if (i * i == number)
			return (i);
		i = i + 0.01;
	}
	return (i);
}
