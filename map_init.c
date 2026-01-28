/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:45:05 by antcamar          #+#    #+#             */
/*   Updated: 2026/01/28 18:47:51 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_sprite(t_lib *lib, t_sprite *sprite, char *path)
{
    sprite->img = mlx_xpm_file_to_image(lib->mlx_p, path, &sprite->width, &sprite->height);
    if (!sprite->img)
    {
        ft_putstr_fd("Failed to load: ", 2);
        ft_putstr_fd(path, 2);
        ft_putstr_fd("\n", 2);
        return (0);
    }
    return (1);
}

int	load_envery_sprites(t_lib *lib)
{
    if (!load_sprite(lib, &lib->wall, "./content/wall.xpm"))
        return (0);
    if (!load_sprite(lib, &lib->floor, "./content/floor.xpm"))
        return (0);
    if (!load_sprite(lib, &lib->player, "./content/player.xpm"))
        return (0);
    if (!load_sprite(lib, &lib->collectible, "./content/collec.xpm"))
        return (0);
    if (!load_sprite(lib, &lib->exit, "./content/exit.xpm"))
        return (0);
    return (1);
}

void	init_mlx(t_lib *lib, t_game *game)
{
    lib->mlx_p = mlx_init();
    if (!lib->mlx_p)
    {
        ft_putstr_fd("MLX initialization failed\n", 2);
        exit(1);
    }
    lib->width = game->size * TILE_SIZE;
    lib->height = game->height * TILE_SIZE;
    lib->win_p = mlx_new_window(lib->mlx_p, lib->width, lib->height, "so_long");
    if (!lib->win_p)
    {
        ft_putstr_fd("Window creation failed\n", 2);
        exit(1);
    }
    if (!load_envery_sprites(lib))
        exit(1);
    render_map(lib, game);
    mlx_loop(lib->mlx_p);
}