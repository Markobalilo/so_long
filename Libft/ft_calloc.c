/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:39:34 by antcamar          #+#    #+#             */
/*   Updated: 2025/11/13 11:45:08 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*
#include <stdio.h>

int	main(void) {
    int *tab = ft_calloc(5, sizeof(int)); 

    for (int i = 0; i < 5; i++)
        printf("tab[%d] = %d\n", i, tab[i]); 

    free(tab);
    return (0);
}
*/