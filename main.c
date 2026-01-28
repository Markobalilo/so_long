/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:10:49 by antcamar          #+#    #+#             */
/*   Updated: 2026/01/28 18:44:50 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(const char *filename, t_game *game, t_lib *lib)
{
    game->verif_c = 0;
    game->verif_e = 0;
    read_map(filename, game);
    check_map(game);
    check_walls(game);
    check_param(game);
    game->mapf = copy_map(game);
    player_pos(game);
    fill(game, game->player_x, game->player_y);
    if (game->verif_e < 1)
    {
        ft_putstr_fd("No exit reachable\n", 2);
        exit(1);
    }
    if (game->c != game->verif_c)
    {
        ft_putstr_fd("No collectibles reachable\n", 2);
        exit(1);
    }
    init_mlx(lib, game);
}

int main(int ac, char **av)
{
    t_game game;
    t_lib lib;

    if (ac == 2)
        fill_map(av[1], &game, &lib);
    return (0);
}