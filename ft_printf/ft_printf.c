/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:33:20 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/19 11:17:56 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char element, va_list *arg)
{
	if (element == 'd' || element == 'i')
		return (ft_putnbr_base(va_arg(*arg, int), "0123456789"));
	else if (element == 'f')
		return (ft_put_float(va_arg(*arg, double)));
	else if (element == 'c')
		return (ft_putchar_fd(va_arg(*arg, int), 1));
	else if (element == 's')
		return (ft_putstr_fd(va_arg(*arg, char *), 1));
	else if (element == 'p')
		return (ft_print_add(va_arg(*arg, void *), 1));
	else if (element == 'x')
		return (ft_putnbr_base(va_arg(*arg, unsigned int), "0123456789abcdef"));
	else if (element == 'X')
		return (ft_putnbr_base(va_arg(*arg, unsigned int), "0123456789ABCDEF"));
	else if (element == 'u')
		return (ft_un_int(va_arg(*arg, unsigned int), 1));
	else if (element == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

static void	print(const char *format, int i, int *count, va_list *p_arg)
{
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				break ;
			*count = *count + check_format(format[++i], p_arg);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
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
