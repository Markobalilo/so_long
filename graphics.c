/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:45:05 by antcamar          #+#    #+#             */
/*   Updated: 2026/01/27 03:35:06 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    show_window(t_lib *lib, t_game *game)
{

    lib->height = game->height;
    lib->width = game->size;

    lib->mlx_p = mlx_init();
    lib->win_p = mlx_new_window(lib->mlx_p, 1920, 1080, "so_long");
    lib->img = mlx_xpm_file_to_image(lib->mlx_p, "./test.xpm", &lib->img_w, &lib->img_h);
    mlx_put_image_to_window(lib->mlx_p, lib->win_p, lib->img,0, 0);
    mlx_loop(lib->mlx_p);
}