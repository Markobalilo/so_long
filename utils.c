/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:14:28 by antcamar          #+#    #+#             */
/*   Updated: 2026/02/05 16:05:09 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_t(char **tab)
{
	size_t	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	openerror(t_game *game, int fd)
{
	if (fd == -1)
	{
		ft_free_t(game->map);
		ft_putstr_fd("Cannot open that file.\n", 2);
		exit(1);
	}
}

void	map_error(t_game *game)
{
	ft_free_t(game->map);
	ft_putstr_fd("The map is not properly surrounded by walls.\n", 2);
	exit(1);
}
