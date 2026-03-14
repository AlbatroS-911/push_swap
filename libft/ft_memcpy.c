/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:28:02 by tokrabem          #+#    #+#             */
/*   Updated: 2026/02/16 20:24:55 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sr;
	size_t			i;

	i = 0;
	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	while (i < n)
	{
		dst[i] = sr[i];
		i++;
	}
	return (dst);
}
