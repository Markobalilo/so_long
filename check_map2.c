/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:26:09 by antcamar          #+#    #+#             */
/*   Updated: 2026/02/06 14:16:06 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(t_game *game, int x, int y)
{
	if (!game || !game->mapf)
		exit(1);
	if (x < 0 || y < 0 || y >= game->height || x >= game->size)
		return ;
	if (!game->mapf[y] || !game->mapf[y][x])
		exit(1);
	if (game->mapf[y][x] == '1' || game->mapf[y][x] == 'K')
		return ;
	if (game->mapf[y][x] == 'C')
		game->verif_c += 1;
	if (game->mapf[y][x] == 'E')
		game->verif_e += 1;
	game->mapf[y][x] = 'K';
	fill(game, x, y - 1);
	fill(game, x, y + 1);
	fill(game, x - 1, y);
	fill(game, x + 1, y);
}

char	**copy_map(t_game *game)
{
	int	i;

	i = -1;
	game->mapf = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->mapf)
	{
		ft_free_t(game->map);
		exit(1);
	}
	while (++i < game->height)
	{
		game->mapf[i] = ft_strdup(game->map[i]);
		if (!game->mapf[i])
		{
			ft_free_t(game->map);
			ft_free_t(game->mapf);
			exit(1);
		}
	}
	game->mapf[i] = 0;
	return (game->mapf);
}

void	player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_y = i;
				game->player_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	attribute_close(const char *filename, int numberl, t_game *game)
{
	int	i;
	int	check;

	i = -1;
	check = open(filename, O_RDONLY);
	if (check < 0)
		openerror(game, check);
	while (++i < numberl)
	{
		game->map[i] = get_next_line(check);
		if (game->map[i] == NULL)
		{
			ft_free_t(game->map);
			close(check);
			exit(1);
		}
	}
	close(check);
	i = 0;
	while (game->map[i])
	{
		if (game->map[i][ft_strlen(game->map[i]) - 1] == '\n')
			game->map[i][ft_strlen(game->map[i]) - 1] = 0;
		i++;
	}
}
