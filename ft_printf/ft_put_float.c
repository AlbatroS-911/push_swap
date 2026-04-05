/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 23:28:55 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/05 23:28:56 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_put_float(double num)
{
	int		integer_part;
	int		fractional_part;
	int		counter;
	int		precision;

	counter = 0;
	precision = 100;
	if (num < 0)
	{
		counter += ft_putchar_fd('-', 1);
		num = -num;
	}
	integer_part = (int)num;
	counter += ft_putnbr_base(integer_part, "0123456789");
	counter += ft_putchar_fd('.', 1);
	fractional_part = (int)((num - integer_part) * precision + 0.5);
	if (fractional_part >= precision)
	{
		fractional_part = 0;
		integer_part++;
	}
	if (fractional_part < 10)
		counter += ft_putchar_fd('0', 1);
	if (fractional_part < 1)
		counter += ft_putchar_fd('0', 1);
	counter += ft_putnbr_base(fractional_part, "0123456789");
	return (counter);
}
