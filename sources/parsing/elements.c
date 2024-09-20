/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:00:36 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/20 15:33:50 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	get_texture_and_color(t_gm *game, char	**matriz)
{
	int		i;
	char	**m;

	i = 0;
	m = matriz;
	while (m[i])
	{
		if (m[i] && (ft_strstr(m[i], "NO ")) && !game->map->ntex)
			game->map->ntex = get_element_info(m[i]);
		else if (m[i] && (ft_strstr(m[i], "SO ")) && !game->map->stex)
			game->map->stex = get_element_info(matriz[i]);
		else if (m[i] && (ft_strstr(m[i], "WE ")) && !game->map->wtex)
			game->map->wtex = get_element_info(m[i]);
		else if (m[i] && (ft_strstr(m[i], "EA ")) && !game->map->etex)
			game->map->etex = get_element_info(m[i]);
		else if (m[i] && (ft_strstr(m[i], "F ")) && !game->map->fc_str)
			game->map->fc_str = get_element_info(m[i]);
		else if (m[i] && (ft_strstr(m[i], "C ")) && !game->map->cc_str)
			game->map->cc_str = get_element_info(m[i]);
		i ++;
	}
}

/**
 * @attention Support function to get_texture_and_color();
 * @brief Extracts the infomation of the PATH of the the texture
 * and trim spaces at the end.
 * @return A trim extracted without spaces at the end
 */
char	*get_element_info(char *line)
{
	int		j;
	int		i;
	char	*extracted;
	char	*trim;

	j = 0;
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i ++;
	while (ft_isalpha(line[i]))
		i ++;
	if (line[i] == ' ' || line[i] == '\t')
	{
		while (line[i] == ' ' || line[i] == '\t')
			i ++;
	}
	j = i;
	while (line[i] != '\0' && line[i] != '\n' && line[i] != '\t')
		i ++;
	extracted = ft_substr(line, j, i - j);
	trim = ft_strtrim(extracted, " ");
	free(extracted);
	return (trim);
}

/**
 * @brief
 * @param m Matriz
 */
bool	is_texture_and_color_valid(t_gm *game, char **m)
{
	int	i;
	int	qt;

	i = 0;
	qt = 0;
	while (m[i])
	{
		if (m[i] && (ft_strstr(m[i], "NO ")
				|| ft_strstr(m[i], "SO ") || ft_strstr(m[i], "WE ")
				|| ft_strstr(m[i], "EA ") || ft_strstr(m[i], "F ")
				|| ft_strstr(m[i], "C ")))
			qt ++;
		i ++;
	}
	if (qt > 6)
		return (ft_err_msg("Duplicated Map Elements", false));
	if (is_spaced(game->map->fc_str) || is_spaced(game->map->cc_str)
		||is_spaced(game->map->ntex) || is_spaced(game->map->stex)
		|| is_spaced(game->map->etex) || is_spaced(game->map->wtex))
		return (ft_err_msg("Invalid Map Element, space in between", false));
	if (is_element_missing(game))
		return (ft_err_msg("Missing map element", false));
	if (!is_rgb_valid(game))
		return (false);
	return (true);
}

/**
 * @brief Check if a word is separated by space
 * example -> "This is Spaced" ; "ThisIsNotSpaced"
 * @return false for not spaced or !str, true for spaced.
 */
bool	is_spaced(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	while (str[i])
	{
		if (str[i + 1] && ft_isalpha(str[i + 1]) && str[i] == ' ')
			return (true);
		if (str[i + 1] && ft_isdigit(str[i + 1]) && str[i] == ' ')
		{
			i ++ ;
			continue ;
		}
		i ++;
	}
	return (false);
}
