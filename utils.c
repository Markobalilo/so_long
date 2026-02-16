/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:14:28 by antcamar          #+#    #+#             */
/*   Updated: 2026/02/16 15:23:10 by antcamar         ###   ########.fr       */
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
		ft_putstr_fd("Error : Cannot open that file.\n", 2);
		exit(1);
	}
}

void	map_error(t_game *game)
{
	if (game->map)
		ft_free_t(game->map);
	if (game->mapf)
		ft_free_t(game->mapf);
	ft_putstr_fd("Error : The map is not properly surrounded by walls.\n", 2);
	exit(1);
}

void	map_invalide(t_game *game, char c)
{
	if (c != '1' && c != '0')
	{
		if (game->map)
			ft_free_t(game->map);
		if (game->mapf)
			ft_free_t(game->mapf);
		ft_putstr_fd("Error : The map is not correct.\n", 2);
		exit(1);
	}
}

void	check_name(const char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	while (i > 0 && filename[i - 1] != '/')
		i--;
	if (ft_strlen(&filename[i]) < 5)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	while (filename[i + 4])
		i++;
	if (ft_strncmp(&filename[i], ".ber", 4))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}
