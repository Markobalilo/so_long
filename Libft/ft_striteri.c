/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:38:47 by antcamar          #+#    #+#             */
/*   Updated: 2025/11/11 15:00:38 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void	xstr(unsigned int i, char *c)
{
	(void)i;
	write(1, c, 1);
	write(1, "xxx", 3);
}

int	main(int ac, char **av)
{
    if (ac > 1)
    {
        ft_striteri(av[1], xstr);
    }
    return (0);
}
*/
