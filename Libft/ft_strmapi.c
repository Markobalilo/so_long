/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:12:59 by antcamar          #+#    #+#             */
/*   Updated: 2025/11/17 16:13:27 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new;
	int		size;

	i = 0;
	size = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * size + 1);
	if (!new)
		return (NULL);
	while (i < size)
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	new[i] = 0;
	return (new);
}
/*
char	touupper(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        c -= 32;
    return (c);
}

int	main(int ac, char **av)
{
    if (ac > 1)
    {
        printf("%s\n", ft_strmapi(av[1], touupper));
    }
    return (0);
}
*/