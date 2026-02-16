/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:10:49 by antcamar          #+#    #+#             */
/*   Updated: 2026/02/16 15:21:55 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(const char *filename, t_game *game, t_lib *lib)
{
	check_name(filename);
	read_map(filename, game);
	check_map(game);
	check_walls(game);
	check_param(game);
	game->mapf = copy_map(game);
	player_pos(game);
	fill(game, game->player_x, game->player_y);
	ft_free_t(game->mapf);
	game->mapf = NULL;
	if (game->verif_e < 1)
	{
		ft_putstr_fd("Error : No exit reachable\n", 2);
		ft_free_t(game->map);
		exit(1);
	}
	if (game->c != game->verif_c)
	{
		ft_putstr_fd("Error : No collectibles reachable\n", 2);
		ft_free_t(game->map);
		exit(1);
	}
	init_mlx(lib, game);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_lib	lib;

	ft_bzero(&game, sizeof(t_game));
	ft_bzero(&lib, sizeof(t_lib));
	if (ac == 2)
		fill_map(av[1], &game, &lib);
	return (0);
}
