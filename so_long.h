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

typedef struct s_game
{
	char	**map;
	int		player_x;
	int		player_y;
	int		height;
	int		size;
	int		e;
	int		c;
	int		p;
	char	**mapf;
	int		verif_e;
	int		verif_c;
}			t_game;

typedef struct s_lib
{
	void	*mlx_p;
	void	*win_p;
	int		height;
	int		width;
	void	*img;
    int     img_h;
    int     img_w;
}			t_lib;

void		ft_free_t(char **tab);
void		read_map(const char *filename, t_game *game);
int			check_map(t_game *game);
int			check_walls(t_game *game);
void		check_param(t_game *game);
void		error_param(t_game *game);
void		fill(t_game *game, int x, int y);
char		**copy_map(t_game *game);
void		player_pos(t_game *game);
void		openerror(int fd);
void		attribute_close(const char *filename, int numberl, t_game *game);
void		map_error(t_game *game);
void		show_window(t_lib *lib, t_game *game);

#endif
