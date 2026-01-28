/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:28:31 by antcamar          #+#    #+#             */
/*   Updated: 2025/11/18 10:55:48 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (i + j < len && needle[j] && haystack[i + j] == needle[j])
		{
			j++;
			if (needle[j] == 0)
				return ((char *)haystack + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
/*
#include <stdio.h>

int main(void) {
    const char *text = "Hello World!";
    const char *sub = "ld";

    char *result = ft_strnstr(text, sub, 11);

    if (result)
        printf("Trouve : %s\n", result);
    else
        printf("Pas trouvé\n");

    return 0;
}
*/