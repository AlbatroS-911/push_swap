/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:57:24 by tokrabem          #+#    #+#             */
/*   Updated: 2026/02/23 20:04:12 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	base_validation(char *base)
{
	int	j;
	int	k;
	int	len_base;

	j = 0;
	k = 1;
	len_base = ft_strlen(base);
	if (len_base < 2)
		return (0);
	while (base[j])
	{
		if ((base[j] == base[k]) || base[j] == '+' || base[j] == '-')
			return (0);
		j++;
		k++;
	}
	return (1);
}

static int	operation(long number, char *base)
{
	int	counter;
	int	len_base;

	counter = 0;
	len_base = ft_strlen(base);
	if (number < 0)
	{
		ft_putchar_fd('-', 1);
		number *= -1;
		counter++;
	}
	if (number >= len_base)
		counter += operation(number / len_base, base);
	ft_putchar_fd(base[number % len_base], 1);
	return (counter + 1);
}

int	ft_putnbr_base(long nbr, char *base)
{
	int	base_check;
	int	counter;

	base_check = base_validation(base);
	if (!base_check || !base)
		return (0);
	counter = operation(nbr, base);
	return (counter);
}
