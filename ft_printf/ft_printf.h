/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:58:03 by tokrabem          #+#    #+#             */
/*   Updated: 2026/03/19 11:25:17 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include "unistd.h"

int		ft_printf(const char *form, ...);
int		ft_putnbr_base(long nbr, char *base);
int		ft_un_int(unsigned int num, int fd);
int		ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
int		ft_putstr_fd(char *s, int fd);
int		ft_print_add(void *address, int fd);
int		ft_put_float(double num);

#endif
