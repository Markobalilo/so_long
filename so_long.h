#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "GNL/get_next_line.h"
# include <sys/stat.h>

typedef struct s_game {
    char **map;  // store lines
    int player_x;
    int player_y;
} t_game;


#endif