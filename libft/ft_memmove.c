/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:59:09 by toky              #+#    #+#             */
/*   Updated: 2026/02/17 09:15:41 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	unsigned char		*sr;
	size_t				i;

	i = 0;
	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	if (dst > sr)
	{
		while (n-- > 0)
			dst[n] = sr[n];
	}
	else
	{
		while (i < n)
		{
			dst[i] = sr[i];
			i++;
		}
	}
	return (dst);
}
