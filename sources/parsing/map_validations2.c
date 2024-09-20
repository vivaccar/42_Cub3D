/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:58:50 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/20 15:31:51 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

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

bool	have_unecessary_line(t_gm *game)
{
	int	i;

	i = 0;
	while (game->map->matriz[i])
	{
		if (is_empty_line(game->map->matriz[i]))
			return (ft_err_msg("Invalid line after map\n", false));
		i ++;
	}
	return (true);
}

/**
 * @brief 
 */
bool	is_line_horizontal_valid(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		jump_spaces(line[i], &i, 0);
	if (line[i] && line[i] != '1')
		return (ft_err_msg("Map horizontal line invalid", false));
	while (line[i])
	{
		if (ft_strchr("NSEW", line[i]))
		{
			if (line[i + 1] && line[i + 1] == ' ')
				return (ft_err_msg("Invalid Player Indication", false));
			i ++;
			continue ;
		}
		if (ft_strchr("01 ", line[i]))
		{
			if ((line[i] == ' ' && line[i + 1] && line[i + 1] == '0')
				|| (line[i] == '0' && line[i + 1] && line[i + 1] == ' '))
				return (ft_err_msg("Map horizontal line invalid", false));
		}
		i ++;
	}
	return (true);
}

/**
 * @brief
 */
bool	is_line_vertical_valid(char **map)
{
	int	line;
	int	chars;
	int	inside_map;
	int	qt_lines;
	int	qt_chars;

	line = 0;
	chars = 0;
	inside_map = 0;
	qt_chars = ft_matriz_big_line(map);
	qt_lines = ft_matrizlen(map);
	while (chars < qt_chars)
	{
		if (line + 1 < qt_lines && (map[line][chars] == ' '
			&& map[line + 1][chars] == ' '))
		{
			line ++ ;
			continue ;
		}
		if (line + 1 < qt_lines && ((map[line][chars] == ' '
				&& map[line + 1][chars] == '0') || (map[line][chars] == '0'
					&& map[line + 1][chars] == ' ')))
			return (ft_err_msg("Invalid Map", false));
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

/**
 * @brief 
*/
bool	is_first_last_valid(char **map)
{
	int	last_line;
	int	j;

	last_line = ft_matrizlen(map) - 1;
	j = 0;
	while (jump_spaces(map[0][j], &j, 0))
		j ++;
	if (ft_strchr(&map[0][j], '0'))
		return (ft_err_msg("First map line invalid!", false));
	j = 0;
	while (jump_spaces(map[last_line][j], &j, 0))
		j ++;
	if (ft_strchr(&map[last_line][j], '0'))
		return (ft_err_msg("Last map line invalid!", false));
	return (true);
}
