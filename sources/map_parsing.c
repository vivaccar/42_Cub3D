/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:36:02 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 17:57:22 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/**
 * @brief Starts the parsing of the map
 * @return EXIT_ERROR for error. EXIT_SUCESS for ok.
 */
int	parse_map(t_gm *game, int argc, char **argv)
{
	int		i;
	char	**cub;

	cub = get_mapfile_info(game, argv[1]);
	i = 0;
	while (cub[i])
	{
		if (cub[i] && ft_strnstr(cub[i], "NO", ft_strlen(cub[i])))
			game->map->ntex = get_element_info(cub[i]);
		else if (cub[i] && ft_strnstr(cub[i], "SO", ft_strlen(cub[i])))
			game->map->stex = get_element_info(cub[i]);
		else if (cub[i] && ft_strnstr(cub[i], "WE", ft_strlen(cub[i])))
			game->map->wtex = get_element_info(cub[i]);
		else if (cub[i] && ft_strnstr(cub[i], "EA", ft_strlen(cub[i])))
			game->map->etex = get_element_info(cub[i]);
		else if (cub[i] && ft_strnstr(cub[i], "F", ft_strlen(cub[i])))
			game->map->f_color = get_element_info(cub[i]);
		else if (cub[i] && ft_strnstr(cub[i], "C", ft_strlen(cub[i])))
			game->map->c_color = get_element_info(cub[i]);
		
		i ++;
	}
	(void)argc;
	printf("game->map->ntex %s \n", game->map->ntex);
	printf("game->map->stex %s \n", game->map->stex);
	printf("game->map->wtex %s \n", game->map->wtex);
	printf("game->map->etex %s \n", game->map->etex);
	printf("game->map->f_color %s", game->map->f_color);
	printf("game->map->c_color %s", game->map->c_color);
	
	ft_free_matriz(cub); // This is just to maintain everything freed
	return (EXIT_SUCCESS);
}

/**
 * @brief Extracts the infomation of the PATH of the the texture
 */
char	*get_element_info(char *line)
{
	int		j;
	int		i;
	char	*extracted;

	j = 0;
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i ++;
	while (ft_isalpha(line[i]))
		i ++;
	j = i;
	while ((line[i])
		&& (line[i] != ' ' || line[i] != '\t' || line[i] != '\n'))
		i ++;
	extracted = ft_substr(line, j, i - j);
	return (extracted);
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
	map = ft_calloc(sizeof(char *), fd_lines_counter(file_path) + 1);
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
 * @brief Used on get_mapfile_info(), to alloc memory to the file
 * @return The number of the lines of a specific fd
 */
int	fd_lines_counter(char *file_path)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (err_msg("Invalid FD", -1));
	i = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i ++;
	}
	free(line);
	close(fd);
	return (i);
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