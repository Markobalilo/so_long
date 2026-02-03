/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 06:31:31 by antcamar          #+#    #+#             */
/*   Updated: 2026/02/03 07:22:55 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(t_game *game, int new_x, int new_y)
{
	char	target;

	if (new_x < 0 || new_x >= game->size || new_y < 0 || new_y >= game->height)
		return (0);
	target = game->map[new_y][new_x];
	if (target == '1' || (target == 'E' && game->collected < game->c))
		return (0);
	if (target == 'C')
		game->collected++;
	if (target == 'E' && game->collected == game->c)
	{
		ft_putstr_fd("Victoire en ", 1);
		ft_putnbr_fd(++game->move, 1);
		ft_putstr_fd(" mouvements!\n", 1);
		exit(0);
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(++game->move, 1);
	return (ft_putchar_fd('\n', 1), 1);
}

int	key_handler(int keycode, t_vars *vars)
{
	int	new_x;
	int	new_y;

	new_x = vars->game->player_x;
	new_y = vars->game->player_y;
	if (keycode == 65307)
	{
		ft_free_t(vars->game->map);
		ft_free_t(vars->game->mapf);
		exit(0);
	}
	else if (keycode == 119 || keycode == 65362)
		new_y--;
	else if (keycode == 115 || keycode == 65364)
		new_y++;
	else if (keycode == 97 || keycode == 65361)
		new_x--;
	else if (keycode == 100 || keycode == 65363)
		new_x++;
	else
		return (0);
	if (move_player(vars->game, new_x, new_y))
		render_map(vars->lib, vars->game);
	return (0);
}

int	close_window(t_vars *vars)
{
	ft_free_t(vars->game->map);
	ft_free_t(vars->game->mapf);
	exit(0);
	return (0);
}
