/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:47:46 by tokrabem          #+#    #+#             */
/*   Updated: 2026/02/15 22:14:09 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_character(long nbr)
{
	int	counter;

	counter = 0;
	if (nbr <= 0)
		counter++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*output;
	size_t	output_length;
	long	nbr;

	nbr = (long)n;
	output_length = count_character(nbr);
	output = (char *)malloc ((output_length + 1) * sizeof(char));
	if (!output)
		return (NULL);
	output[output_length] = '\0';
	if (nbr == 0)
		output[0] = '0';
	if (nbr < 0)
	{
		nbr = nbr * -1;
		output[0] = '-';
	}
	while (nbr > 0)
	{
		output[--output_length] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (output);
}
