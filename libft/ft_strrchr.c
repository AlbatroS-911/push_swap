/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 09:00:10 by tokrabem          #+#    #+#             */
/*   Updated: 2026/02/16 19:47:43 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;

	count = ft_strlen(s) + 1;
	while (count-- > 0)
	{
		if (s[count] == (char)c)
			return ((char *)&s[count]);
	}
	return (NULL);
}
