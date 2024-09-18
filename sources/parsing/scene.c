/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:36:02 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/18 11:51:05 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

/**
 * @brief Starts the parsing of the map
 * @return EXIT_ERROR for error. EXIT_SUCESS for ok.
 */
int	parse_file(t_gm *game, int argc, char **argv)
{
	char	**cub;

	cub = get_mapfile_info(game, argv[1]);
	replace_tabs_to_space(cub);
	get_texture_and_color(game, cub);
	if (!is_texture_and_color_valid(game, cub))
		return (ft_free_matriz(cub), EXIT_FAILURE);
	extract_map(game, cub);
	//validate map
	if (!is_map_valid(game))
		return (ft_free_matriz(cub), EXIT_FAILURE);
	ft_free_matriz(cub);
	(void)argc;
	return (EXIT_SUCCESS);
}

/**
 * @brief Extract the map informations from a fd file
 */
char	**get_mapfile_info(t_gm *game, char *file_path)
{
	char	*line;
	char	**map;
	int		i;

	if (!game)
		return (NULL);
	map = ft_calloc(sizeof(char *), ft_fd_lines_counter(file_path) + 1);
	if (!map)
		return (NULL);
	line = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(game->map->fd);
		if (!line)
			break ;
		map[i] = ft_strdup(line);
		free(line);
		i ++;
	}
	close(game->map->fd);
	return (map);
}

/**
 * @brief Replace tabs for spaces in the matriz
 */
void	replace_tabs_to_space(char **cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub[i])
	{
		j = 0;
		while (cub[i][j] != '\0' && cub[i][j] != '\n')
		{
			if (cub[i][j] == '\t')
				cub[i][j] = ' ';
			j ++;
		}
		i ++;
	}
}

//The map must be composed of only 6 possible characters: 0 for an empty space,
//1 for a wall, and N,S,E or W for the player’s start position and spawning
//orientation

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

//The map must be composed of only 6 possible characters: 0 for an empty space,
//1 for a wall, and N,S,E or W for the player’s start position and spawning
//orientation.


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