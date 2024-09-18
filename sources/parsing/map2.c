/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:49:57 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/18 16:02:17 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

bool	is_map_valid(t_gm *game)
{
	if (game->map->matriz[0] == NULL)
		return (ft_err_msg("Empty Map!", false));
	if (!is_player_valid(game))
		return (false);
	printf("%c \n", game->map->plyr_dir);
	return (true);
}

bool	is_player_valid(t_gm *game)
{
	int		i;
	int		j;
	int		qt;

	i = -1;
	j = 0;
	qt = 0;
	while(game->map->matriz[++ i])
	{
		j = -1;
		while (game->map->matriz[i][++ j])
		{
			if (ft_strchr("NSEW", game->map->matriz[i][j]))
			{
				qt ++;
				game->map->plyr_x = j;
				game->map->plyr_y = i;
				game->map->plyr_dir = game->map->matriz[i][j];
				
			}
		}
	}
	if (qt != 1)
		return (ft_err_msg("Invalid Player Indication", false));
	return (true);
}


//The map must be composed of only 6 possible characters: 0 for an empty space,
//1 for a wall, and N,S,E or W for the player’s start position and spawning
//orientation.

/*
The map must be closed/surrounded by walls, if not the program must return
an error.

◦ Except for the map content, each type of element can be separated by one or
more empty line(s).

◦ Except for the map content which always has to be the last, each type of
element can be set in any order in the file.

◦ Except for the map, each type of information from an element can be separated
by one or more space(s).

◦ The map must be parsed as it looks in the file. Spaces are a valid part of the
map and are up to you to handle. You must be able to parse any kind of map,
as long as it respects the rules of the map.
*/


/* map structure {
	char **map;
	char *north_texture;
	char *south_texture;
	char *west_texture;
	char *east_texture;
	char *floor_color;
	char *ceiling_color;
	char player_direction;
	double player_position_X;
	double player_position_Y;
	double plane_x;
	double plane_y;


	} */