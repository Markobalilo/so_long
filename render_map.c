/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:38:20 by antcamar          #+#    #+#             */
/*   Updated: 2026/02/03 07:25:13 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	r_tile(t_lib *lib, char tile, int x, int y)
{
	int	px;
	int	py;

	px = x * TILE_SIZE;
	py = y * TILE_SIZE;
	mlx_put_image_to_window(lib->mlx_p, lib->win_p, lib->floor.img, px, py);
	if (tile == '1')
		mlx_put_image_to_window(lib->mlx_p, lib->win_p, lib->wall.img, px, py);
	else if (tile == 'C')
		mlx_put_image_to_window(lib->mlx_p, lib->win_p, lib->collectible.img,
			px, py);
	else if (tile == 'E')
		mlx_put_image_to_window(lib->mlx_p, lib->win_p, lib->exit.img, px, py);
	else if (tile == 'P')
		mlx_put_image_to_window(lib->mlx_p, lib->win_p, lib->player.img, px,
			py);
}

void	render_map(t_lib *lib, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->size)
		{
			r_tile(lib, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
