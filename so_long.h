/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:38:24 by antcamar          #+#    #+#             */
/*   Updated: 2026/02/17 13:29:58 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "GNL/get_next_line.h"
# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# define TILE_SIZE 64

typedef struct s_sprite
{
	void		*img;
	int			width;
	int			height;
}				t_sprite;

typedef struct s_game
{
	char		**map;
	int			player_x;
	int			player_y;
	int			height;
	int			size;
	int			e;
	int			c;
	int			p;
	char		**mapf;
	int			verif_e;
	int			verif_c;
	int			move;
	int			collected;
	char		pre_tile;
}				t_game;

typedef struct s_lib
{
	void		*mlx_p;
	void		*win_p;
	int			height;
	int			width;
	t_sprite	player;
	t_sprite	wall;
	t_sprite	floor;
	t_sprite	collectible;
	t_sprite	exit;
}				t_lib;

typedef struct s_vars
{
	t_lib		*lib;
	t_game		*game;
}				t_vars;

void			ft_free_t(char **tab);
void			read_map(const char *filename, t_game *game);
int				check_map(t_game *game);
int				check_walls(t_game *game);
void			check_param(t_game *game);
void			error_param(t_game *game);
void			fill(t_game *game, int x, int y);
char			**copy_map(t_game *game);
void			player_pos(t_game *game);
void			openerror(t_game *game, int fd);
void			attribute_close(const char *filename, int numberl,
					t_game *game);
void			map_error(t_game *game);
void			show_window(t_lib *lib, t_game *game);
void			init_mlx(t_lib *lib, t_game *game);
void			load_sprite(t_lib *lib, t_sprite *sprite, char *path,
					t_game *game);
void			load_envery_sprites(t_lib *lib, t_game *game);
void			r_tile(t_lib *lib, char tile, int x, int y);
void			render_map(t_lib *lib, t_game *game);
int				move_player(t_vars *vars, t_game *game, int new_x, int new_y);
int				key_handler(int keycode, t_vars *vars);
int				close_window(t_vars *vars);
void			close_window2(t_lib *lib, t_game *game);
void			init_mlx2(t_lib *lib, t_game *game);
void			map_invalide(t_game *game, char c);
void			check_name(const char *filename);
int				check_screen(t_game *game, t_lib *lib);
#endif
