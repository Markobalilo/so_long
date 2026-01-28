/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:47:16 by antcamar          #+#    #+#             */
/*   Updated: 2025/11/18 10:16:24 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/*
int main(void)
{
    t_list a = {"Un", NULL};
    t_list b = {"Deux", NULL};
    t_list c = {"Trois", NULL};
	t_list d = {"Quatre", NULL};


    a.next = &b;
    b.next = &c;
	c.next = &d;

    printf("Taille : %d\n", ft_lstsize(&a));

    return 0;
}
*/
