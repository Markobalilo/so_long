/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:48:12 by antcamar          #+#    #+#             */
/*   Updated: 2025/11/18 10:05:22 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
/*
int main(void)
{
    t_list a = {"Hello", NULL};
    t_list b = {"World", NULL};
    a.next = &b;

    t_list *last = ft_lstlast(&a);
    printf("%s\n", (char *)last->content);
}
*/