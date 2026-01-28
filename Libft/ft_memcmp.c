/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:42:21 by antcamar          #+#    #+#             */
/*   Updated: 2025/11/10 14:10:17 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*str1t;
	unsigned char	*str2t;

	str1t = (unsigned char *)str1;
	str2t = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (str1t[i] != str2t[i])
		{
			return (str1t[i] - str2t[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac < 2)
		return 0;
	else
		printf("%d", ft_memcmp(av[1], av[2], 5));
	return 0;

}
*/
