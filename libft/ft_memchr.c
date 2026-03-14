/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:58:29 by tokrabem          #+#    #+#             */
/*   Updated: 2026/02/15 20:35:09 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*str;

	str = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		if (str[count] == (unsigned char)c)
			return (&str[count]);
		count++;
	}
	return (NULL);
}
