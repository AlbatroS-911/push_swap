/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:09:58 by tokrabem          #+#    #+#             */
/*   Updated: 2026/02/23 20:06:23 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_un_int(unsigned int num, int fd)
{
	int	counter;

	counter = 0;
	if (num >= 10)
		counter += ft_un_int(num / 10, fd);
	ft_putchar_fd((num % 10) + 48, fd);
	return (counter + 1);
}
