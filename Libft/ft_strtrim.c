/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:12:26 by antcamar          #+#    #+#             */
/*   Updated: 2025/11/18 10:44:00 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_set(s1[start], set) == 1)
	{
		start++;
	}
	end = ft_strlen(s1);
	while (end > start && is_set(s1[end - 1], set) == 1)
	{
		end--;
	}
	return (ft_substr(s1, start, end - start));
}
/*
int main()
{
	printf("%s\n", ft_strtrim("Koznav", "Ko"));
}
*/