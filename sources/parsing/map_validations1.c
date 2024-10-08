/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:49:57 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/07 15:42:23 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

/**
 * @brief Anchor function to check the validation of the map
 * If everything is ok, returns true.
 * Else, returns false.
*/
bool	is_map_valid(t_gm *game)
{
	char	**m_copy;

	if (game->map->matriz[0] == NULL)
		return (ft_err_msg("Empty Map!", false));
	m_copy = ft_matrizdup(game->map->matriz);
	if (!have_onlyvalid_ch(game) || !are_all_lines_valid(game)
		|| !is_player_valid(game) || !is_map_closed(m_copy))
		return (ft_free_matriz(m_copy), false);
	game->map->h = ft_matrizlen(game->map->matriz);
	game->map->w = ft_matriz_big_line(game->map->matriz);
	ft_free_matriz(m_copy);
	return (true);
}

/**
 * @brief Check of there is more or less than 1 player on the map
*/
bool	is_player_valid(t_gm *game)
{
	int		i;
	int		j;
	int		qt;

	i = -1;
	j = 0;
	qt = 0;
	while (game->map->matriz[++ i])
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
		return (ft_err_msg("Invalid player on map", false));
	return (true);
}

/**
 * @brief Check if there is only valid characters on the map
*/
bool	have_onlyvalid_ch(t_gm *game)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (game->map->matriz[++ i])
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

/**
 * @attention Support function to is_valid_map()
 * Anchor function to validations of closed map.
 * @brief Check if the map is closed and all the lines are valid.
*/
bool	is_map_closed(char	**map)
{
	int	i;

	if (!is_last_column_closed(map)
		||!is_line_vertical_valid(map) || !is_first_last_valid(map))
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

/**
 * @brief Check if the last column is closed by walls.
*/
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
				continue ;
			if (map[i][j] != '1')
				return (ft_err_msg("Map last column invalid!", false));
			else
				break ;
		}
		i ++;
	}
	return (true);
}

/* bool flood_fill(t_gm *game, char **map, int y, int x)
{
    // Ensure we are within map bounds
    if (x < 0 || x >= game->map->w || y < 0 || y >= game->map->h)
        return (false);

    // If current cell is already visited ('X') 
	or is a wall ('1'), return true (valid wall)
    if (map[y][x] == '1' || map[y][x] == 'X')
        return (true);

    // If current cell is an open space ('0') 
	or start position ('S'), mark as visited
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
