/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:56:46 by antcamar          #+#    #+#             */
/*   Updated: 2025/11/12 12:07:06 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_t;
	unsigned char	*src_t;

	src_t = (unsigned char *)src;
	dest_t = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest_t[i] = src_t[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char str[] = "Salut frr";
	
	printf("%s\n", str);
	ft_memcpy(str, str + 6, 3 * sizeof(char));
	printf("%s\n", str);

	return 0;

}
*/