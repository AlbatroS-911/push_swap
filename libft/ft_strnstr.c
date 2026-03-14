/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:12:19 by tokrabem          #+#    #+#             */
/*   Updated: 2026/02/15 23:01:07 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	if (big[0] == '\0')
		return (NULL);
	if (len >= 0)
	{
		while (big[i] && i < len)
		{
			j = 0;
			while ((big[i + j] == little[j]) && little[j] && (i + j) < len)
			{
				j++;
				if (little[j] == '\0')
					return ((char *)&big[i]);
			}
			i++;
		}
	}
	return (NULL);
}
