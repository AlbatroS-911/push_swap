/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrabem <tokrabem@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:35:16 by tokrabem          #+#    #+#             */
/*   Updated: 2026/02/18 13:06:55 by tokrabem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contain(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] && set[i] != c)
		i++;
	return (set[i] == c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	char	*trimmed_str;

	beg = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	if (!set)
		return (ft_strdup(s1));
	if (beg == end)
		return (ft_strdup(""));
	while (contain(set, s1[beg]))
		beg++;
	while (contain(set, s1[end]))
		end--;
	trimmed_str = ft_substr(s1, beg, end - (beg - 1));
	return (trimmed_str);
}
