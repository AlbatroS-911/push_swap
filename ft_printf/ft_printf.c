/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:33:20 by tokrabem          #+#    #+#             */
/*   Updated: 2026/04/09 21:48:10 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char element, va_list *arg, int fd)
{
	if (element == 'd' || element == 'i')
		return (ft_putnbr_base(va_arg(*arg, int), "0123456789", fd));
	else if (element == 'f')
		return (ft_put_float(va_arg(*arg, double), fd));
	else if (element == 'c')
		return (ft_putchar_fd(va_arg(*arg, int), fd));
	else if (element == 's')
		return (ft_putstr_fd(va_arg(*arg, char *), fd));
	else if (element == 'p')
		return (ft_print_add(va_arg(*arg, void *), fd));
	else if (element == 'x')
		return (ft_putnbr_base(va_arg(*arg, unsigned int), "0123456789abcdef",
				fd));
	else if (element == 'X')
		return (ft_putnbr_base(va_arg(*arg, unsigned int), "0123456789ABCDEF",
				fd));
	else if (element == 'u')
		return (ft_un_int(va_arg(*arg, unsigned int), fd));
	else if (element == '%')
		return (ft_putchar_fd('%', fd));
	return (0);
}

static void	print(const char *format, int i, int *count, va_list *p_arg)
{
	int	fd;

	fd = 2;
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				break ;
			*count = *count + check_format(format[++i], p_arg, fd);
		}
		else
		{
			ft_putchar_fd(format[i], fd);
			(*count)++;
		}
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	p_arg;
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(p_arg, format);
	print(format, i, &count, &p_arg);
	va_end(p_arg);
	return (count);
}
