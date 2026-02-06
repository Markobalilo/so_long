/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:14:28 by antcamar          #+#    #+#             */
/*   Updated: 2026/02/06 14:15:41 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_t(char **tab)
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

void	openerror(t_game *game, int fd)
{
	if (fd == -1)
	{
		if (game->map)
			ft_free_t(game->map);
		ft_putstr_fd("Cannot open that file.\n", 2);
		exit(1);
	}
}

void	map_error(t_game *game)
{
	if (game->map)
		ft_free_t(game->map);
	if (game->mapf)
		ft_free_t(game->mapf);
	ft_putstr_fd("The map is not properly surrounded by walls.\n", 2);
	exit(1);
}
