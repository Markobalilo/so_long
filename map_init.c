/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:45:05 by antcamar          #+#    #+#             */
/*   Updated: 2026/02/16 15:21:37 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprite(t_lib *lib, t_sprite *sprite, char *path, t_game *game)
{
	sprite->img = mlx_xpm_file_to_image(lib->mlx_p, path, &sprite->width,
			&sprite->height);
	if (!sprite->img)
	{
		ft_putstr_fd("Error : Failed to load: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		close_window2(lib, game);
	}
}

void	load_envery_sprites(t_lib *lib, t_game *game)
{
	load_sprite(lib, &lib->wall, "./content/wall.xpm", game);
	load_sprite(lib, &lib->floor, "./content/floor.xpm", game);
	load_sprite(lib, &lib->player, "./content/player.xpm", game);
	load_sprite(lib, &lib->collectible, "./content/collec.xpm", game);
	load_sprite(lib, &lib->exit, "./content/exit.xpm", game);
}

void	close_window2(t_lib *lib, t_game *game)
{
	if (game->map)
		ft_free_t(game->map);
	if (lib->floor.img)
		mlx_destroy_image(lib->mlx_p, lib->floor.img);
	if (lib->player.img)
		mlx_destroy_image(lib->mlx_p, lib->player.img);
	if (lib->wall.img)
		mlx_destroy_image(lib->mlx_p, lib->wall.img);
	if (lib->exit.img)
		mlx_destroy_image(lib->mlx_p, lib->exit.img);
	if (lib->collectible.img)
		mlx_destroy_image(lib->mlx_p, lib->collectible.img);
	if (lib->mlx_p && lib->win_p)
		mlx_destroy_window(lib->mlx_p, lib->win_p);
	if (lib->mlx_p)
	{
		mlx_destroy_display(lib->mlx_p);
		if (lib->mlx_p)
			free(lib->mlx_p);
	}
	exit(0);
}

void	init_mlx(t_lib *lib, t_game *game)
{
	lib->mlx_p = mlx_init();
	if (!lib->mlx_p)
	{
		ft_free_t(game->map);
		ft_putstr_fd("Error : MLX failed\n", 2);
		exit(1);
	}
	lib->width = game->size * TILE_SIZE;
	lib->height = game->height * TILE_SIZE;
	lib->win_p = mlx_new_window(lib->mlx_p, lib->width, lib->height, "so_long");
	if (!lib->win_p)
	{
		ft_putstr_fd("Error : Window failed\n", 2);
		close_window2(lib, game);
		exit(1);
	}
	load_envery_sprites(lib, game);
	init_mlx2(lib, game);
}

void	init_mlx2(t_lib *lib, t_game *game)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		close_window2(lib, game);
	vars->lib = lib;
	vars->game = game;
	render_map(lib, game);
	game->pre_tile = '0';
	mlx_hook(lib->win_p, 2, 1L, key_handler, vars);
	mlx_hook(lib->win_p, 17, 0, close_window, vars);
	mlx_loop(lib->mlx_p);
}
