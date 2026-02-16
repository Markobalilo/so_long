/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 06:31:31 by antcamar          #+#    #+#             */
/*   Updated: 2026/02/16 15:23:05 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player2(t_game *game, int new_x, int new_y)
{
	char	target;

	target = game->map[new_y][new_x];
	if (target != 'C')
		game->pre_tile = target;
	game->map[new_y][new_x] = 'P';
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(++game->move, 1);
}

int	move_player(t_vars *vars, t_game *game, int new_x, int new_y)
{
	char	target;

	if (new_x < 0 || new_x >= game->size || new_y < 0 || new_y >= game->height)
		return (0);
	target = game->map[new_y][new_x];
	if (target == '1')
		return (0);
	if (target == 'C')
		game->collected++;
	if (target == 'E' && game->collected == game->c)
	{
		ft_putstr_fd("Victoire en ", 1);
		ft_putnbr_fd(++game->move, 1);
		ft_putstr_fd(" mouvements!\n", 1);
		close_window(vars);
		exit(0);
	}
	game->map[game->player_y][game->player_x] = game->pre_tile;
	game->player_x = new_x;
	game->player_y = new_y;
	game->pre_tile = '0';
	move_player2(game, new_x, new_y);
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
		close_window(vars);
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
	if (move_player(vars, vars->game, new_x, new_y))
		render_map(vars->lib, vars->game);
	return (0);
}

int	close_window(t_vars *vars)
{
	if (vars->game->map)
		ft_free_t(vars->game->map);
	if (vars->game->mapf)
		ft_free_t(vars->game->mapf);
	if (vars->lib->floor.img)
		mlx_destroy_image(vars->lib->mlx_p, vars->lib->floor.img);
	if (vars->lib->player.img)
		mlx_destroy_image(vars->lib->mlx_p, vars->lib->player.img);
	if (vars->lib->wall.img)
		mlx_destroy_image(vars->lib->mlx_p, vars->lib->wall.img);
	if (vars->lib->exit.img)
		mlx_destroy_image(vars->lib->mlx_p, vars->lib->exit.img);
	if (vars->lib->collectible.img)
		mlx_destroy_image(vars->lib->mlx_p, vars->lib->collectible.img);
	if (vars->lib && vars->lib->win_p)
		mlx_destroy_window(vars->lib->mlx_p, vars->lib->win_p);
	if (vars->lib->mlx_p)
	{
		mlx_destroy_display(vars->lib->mlx_p);
		if (vars->lib->mlx_p)
			free(vars->lib->mlx_p);
	}
	if (vars)
		free(vars);
	exit(0);
}
