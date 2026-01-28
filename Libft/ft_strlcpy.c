/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:53:01 by antcamar          #+#    #+#             */
/*   Updated: 2025/11/12 11:16:01 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (size == 0)
		return (j);
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}
/*
#include <stdio.h>

int	main(void)
{
	char src[] = "bonjour";
	char	dest[10];
	size_t	len;

	len = ft_strlcpy(dest, src, 4);
	printf("Source : %s\n", src);
	printf("Destination : %s\n", dest);
	printf("Longueur de src : %zu\n", len);
	return (0);
}
*/