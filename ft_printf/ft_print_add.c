/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:27:39 by tokrabem          #+#    #+#             */
/*   Updated: 2026/02/23 20:37:17 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_add(unsigned long num)
{
	int		counter;
	char	*base;

	counter = 0;
	base = "0123456789abcdef";
	if (num >= 16)
		counter += ft_puthex_add(num / 16);
	ft_putchar_fd(base[num % 16], 1);
	return (counter + 1);
}

int	ft_print_add(void *address, int fd)
{
	int	counter;

	counter = 0;
	if (address == NULL)
	{
		counter += ft_putstr_fd("(nil)", fd);
		return (counter);
	}
	ft_putstr_fd("0x", 1);
	counter += ft_puthex_add((unsigned long)address);
	return (ft_strlen("0x") + counter);
}
