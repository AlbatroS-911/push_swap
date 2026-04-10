/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 23:28:55 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/10 07:00:38 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fractional(double num, int integer_part, int fd)
{
	int	counter;
	int	precision;
	int	fractional_part;

	counter = 0;
	precision = 100;
	fractional_part = (int)((num - integer_part) * precision + 0.5);
	counter += ft_putchar_fd('.', fd);
	if (fractional_part >= precision)
		fractional_part = 0;
	if (fractional_part == 0)
	{
		counter += ft_putchar_fd('0', fd);
		counter += ft_putchar_fd('0', fd);
		return (counter);
	}
	if (fractional_part < 10)
		counter += ft_putchar_fd('0', fd);
	counter += ft_putnbr_base(fractional_part, "0123456789", fd);
	return (counter);
}

int	ft_put_float(double num, int fd)
{
	int	integer_part;
	int	counter;

	counter = 0;
	if (num < 0)
	{
		counter += ft_putchar_fd('-', fd);
		num = -num;
	}
	integer_part = (int)num;
	counter += ft_putnbr_base(integer_part, "0123456789", fd);
	counter += ft_fractional(num, integer_part, fd);
	return (counter);
}
