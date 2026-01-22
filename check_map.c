/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:09:22 by antcamar          #+#    #+#             */
/*   Updated: 2026/01/22 17:38:49 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(const char *filename, t_game *game)
{
	int		check;
	char	*result;
	int		i;
	int		numberl;

	i = -1;
	numberl = 0;
	check = open(filename, O_RDONLY);
	result = get_next_line(check);
	while (result != NULL)
	{
		numberl++;
		free(result);
		result = get_next_line(check);
	}
	game->map = (char **)malloc(sizeof(char *) * numberl);
	if (!game->map)
		return ;
	close(check);
	check = open(filename, O_RDONLY);
	while (++i < numberl)
		game->map[i] = get_next_line(check);
	close(check);
}

int check_map(t_game *game)
{
    int i;
    int len;

    if(!game->map)
        return (1);
    i = 0;
    len = ft_strlen(game->map[0]);
    while (game->map[i])
    {
        if (ft_strlen(game->map[i]) != len)
            return(1);
        i++;
    }    
    return (0);  
}
