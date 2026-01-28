/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:43:20 by antcamar          #+#    #+#             */
/*   Updated: 2025/11/18 09:51:56 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	ft_allocate(char **tab, char const *s, char sep)
{
	char const	*tmp;
	int			i;

	i = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		tmp = s;
		while (*tmp && *tmp != sep)
			tmp++;
		if (tmp > s)
		{
			tab[i] = ft_substr(s, 0, tmp - s);
			if (!tab[i])
				return (0);
			i++;
			s = tmp;
		}
	}
	tab[i] = NULL;
	return (1);
}

static int	ft_count_words(char const *s, char sep)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
			count++;
		while (*s && *s != sep)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	new = malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	if (!ft_allocate(new, s, c))
	{
		free_tab(new);
		return (NULL);
	}
	return (new);
}

/*
#include <stdio.h>

int	main(void)
{
	int		i;
	char	**res;

	i = 0;
	char str[] = "Salut,A,tou,s,les,amis";
	printf("Test 1:\n");
	res = ft_split(str, ',');
	for (i = 0; res[i] != NULL; i++)
		printf("res[%d] = '%s'\n", i, res[i]);
	for (i = 0; res[i] != NULL; i++)
		free(res[i]);
	free(res);
}
*/
