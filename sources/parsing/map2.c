/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:49:57 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/19 21:41:03 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

bool	is_map_valid(t_gm *game)
{
	char	**m_copy;

	if (game->map->matriz[0] == NULL)
		return (ft_err_msg("Empty Map!", false));
	if (!have_onlyvalid_ch(game))
		return (false);
	clean_unecessary_spaces(game);
	m_copy = ft_matrizdup(game->map->matriz);
	if (!is_player_valid(game) || !is_map_closed(m_copy))
	 	return (ft_free_matriz(m_copy), false);
	game->map->h = ft_matrizlen(game->map->matriz);
	game->map->w = ft_matriz_big_line(game->map->matriz);
	ft_free_matriz(m_copy);
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

bool	have_onlyvalid_ch(t_gm *game)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while(game->map->matriz[++ i])
	{
		j = -1;
		while (game->map->matriz[i][++ j])
		{
			if (!ft_strchr("01NSEW ", game->map->matriz[i][j]))
				return (ft_err_msg("Invalid Character on map!", false));
		}
	}
	return (true);
}

bool	is_map_closed(char	**map)
{
	int	i;

	if (!is_first_column_closed(map) || !is_last_column_closed(map)
	|| !is_line_vertical_valid(map))
		return (false);
	i = 0;
	while (map[i])
	{
		if (!is_line_horizontal_valid(map[i]))
			return (false);
		i ++;
	}
	
	return (true);
}

bool	is_first_column_closed(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (jump_spaces(map[i][j], &j, 0))
				continue;
			if (map[i][j] != '1')
				return (ft_err_msg("Open map, first column open!", false));
			else
				break ;
		}
		i ++;
	}
	return (true);
}

bool	is_last_column_closed(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = ft_strlen(map[i]) - 1;
		while (map[i][j])
		{
			if (jump_spaces(map[i][j], &j, 1))
				continue;
			if (map[i][j] != '1')
				return (ft_err_msg("Open map, last column open!", false));
			else
				break ;
		}
		i ++;
	}
	return (true);
}

bool	jump_spaces(char ch, int *j, int backwards)
{
	if (ch == ' ' && !backwards)
	{
		(*j)++;
		return (true);
	}
	if (ch == ' ' && backwards)
	{
		(*j)--;
		return (true);
	}
	return (false);
}
/**
 * @brief Mexo com os CHARS
 */
bool	is_line_horizontal_valid(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		jump_spaces(line[i], &i, 0);
	if (line[i] && line[i] != '1')
		return (ft_err_msg("Invalid Map", false));
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ' && line[i] != '0')
		{
			if (ft_strchr("NSEW", line[i]))
			{
				i ++;
				continue ;
			}
			return (ft_err_msg("Invalid Map", false));
		}
		if (ft_strchr("01 ", line[i]))
		{
			if (line[i] == ' ' && line[i + 1] && line[i + 1] == '0')
				return (ft_err_msg("Invalid Map", false));
			if (line[i] == '0' && line[i + 1] && line[i + 1] == ' ')
				return (ft_err_msg("Invalid Map", false));
		}
		i ++;	
	}
	return (true);
}

/**
 * TENHO QUE MEXER COM A LINHA
 */
bool	is_line_vertical_valid(char **map)
{
	int	line;
	int chars;
	int	qt_lines = ft_matrizlen(map);
	int qt_chars = ft_matriz_big_line(map);

	line = 0;
	chars = 0;
	while (map[line + 1] && map[line][chars] == ' ')
		jump_spaces(map[line][chars], &line, 0);
	while (chars < qt_chars)
	{
		if (line + 1 < qt_lines && ((map[line][chars] == ' ' 
				&& map[line + 1][chars] == '0') || (map[line][chars] == '0'
					&& map[line + 1][chars] == ' ')))
			return (ft_err_msg("Open in vertical", false));
		if ((line == qt_lines) && (chars == qt_chars))
			break ;
		line ++;
		if (line == qt_lines)
		{
			line = 0;
			chars ++;
		}
	}
	return (true);
}


/* bool flood_fill(t_gm *game, char **map, int y, int x)
{
    // Ensure we are within map bounds
    if (x < 0 || x >= game->map->w || y < 0 || y >= game->map->h)
        return (false);

    // If current cell is already visited ('X') or is a wall ('1'), return true (valid wall)
    if (map[y][x] == '1' || map[y][x] == 'X')
        return (true);

    // If current cell is an open space ('0') or start position ('S'), mark as visited
    if (map[y][x] == '0' || map[y][x] == 'S')
        map[y][x] = 'X'; // Mark the cell as visited
    else
        // If the cell is not a valid space, return false (it's invalid)
        return (false);

    // Recursively check all four directions: down, up, right, left
    if (!flood_fill(game, map, y + 1, x) || // Down
        !flood_fill(game, map, y - 1, x) || // Up
        !flood_fill(game, map, y, x + 1) || // Right
        !flood_fill(game, map, y, x - 1))   // Left
        return (false);

    // If all directions return true, the map is closed
    return (true);
} */


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