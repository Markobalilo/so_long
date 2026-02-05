/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:09:22 by antcamar          #+#    #+#             */
/*   Updated: 2026/02/05 16:13:48 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(const char *filename, t_game *game)
{
	int		check;
	char	*result;
	int		numberl;

	numberl = 0;
	check = open(filename, O_RDONLY);
	openerror(game, check);
	result = get_next_line(check);
	while (result != NULL)
	{
		numberl++;
		free(result);
		result = get_next_line(check);
	}
	game->height = numberl;
	game->map = (char **)malloc(sizeof(char *) * numberl + 1);
	close(check);
	if (!game->map)
		exit (1);
	game->map[numberl] = 0;
	attribute_close(filename, numberl, game);
}

int	check_map(t_game *game)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(game->map[0]);
	game->size = len;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != len)
		{
			ft_free_t(game->map);
			exit (1);
		}
		i++;
	}
	return (0);
}

int	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->size)
	{
		if (game->map[0][i] != '1')
			map_error(game);
		if (game->map[game->height - 1][i] != '1')
			map_error(game);
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1')
			map_error(game);
		if (game->map[i][game->size - 1] != '1')
			map_error(game);
		i++;
	}
	return (0);
}

void	check_param(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->e = 0;
	game->c = 0;
	game->p = 0;
	while (i < game->height)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				game->e++;
			if (game->map[i][j] == 'C')
				game->c++;
			if (game->map[i][j] == 'P')
				game->p++;
			j++;
		}
		i++;
	}
	error_param(game);
}

void	error_param(t_game *game)
{
	if (game->c == 0)
		ft_putstr_fd("Not enough collectibles\n", 2);
	if (game->p == 0)
		ft_putstr_fd("Not enough player\n", 2);
	if (game->p > 1)
		ft_putstr_fd("Too many players \n", 2);
	if (game->e != 1)
		ft_putstr_fd("No exit available\n", 2);
	if (game->c == 0 || game->p == 0 || game->e != 1 || game->p > 1)
	{
		ft_free_t(game->map);
		exit (1);
	}
}
