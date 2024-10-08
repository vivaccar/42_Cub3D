/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:40:39 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/07 12:56:05 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_bonus.h"

/**
 * @brief Function that extracts the part of the map from the file
 */
void	extract_map(t_gm *game, char **scene)
{
	int	start;

	start = find_starting_point(scene);
	game->map->matriz = ft_matrizdup(&scene[start]);
	if (game->map->matriz[0] == NULL)
		return ;
	make_map_rectangle(game);
}

/**
 * @brief Return the first line after
 */
int	find_starting_point(char **scene)
{
	int	i;
	int	qt;

	i = 0;
	qt = 0;
	while (scene[i])
	{
		if (scene[i] && (ft_strstr(scene[i], "NO ")
				|| ft_strstr(scene[i], "SO ") || ft_strstr(scene[i], "WE ")
				|| ft_strstr(scene[i], "EA ") || ft_strstr(scene[i], "F ")
				|| ft_strstr(scene[i], "C ")))
			qt ++;
		i ++;
		if (qt == 6)
			break ;
	}
	while (scene[i] && is_empty_line(scene[i]))
		i ++;
	return (i);
}

/**
 * Check if the function has only spaces
 */
bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (false);
		i ++;
	}
	return (true);
}

/**
 * @brief Make the map a rectable using the biggest line as reference.
 * This will put spaces after the '\n' or '\0' (in case of last line)
 * until it get the len of biggest line.
 * @details big_line - 1 for for consdering the '\n'.
 */
void	make_map_rectangle(t_gm *game)
{
	int		big_line;
	int		i;
	char	**matriz_dup;

	big_line = ft_matriz_big_line(game->map->matriz);
	matriz_dup = ft_matrizdup(game->map->matriz);
	i = 0;
	while (matriz_dup[i])
	{
		free(game->map->matriz[i]);
		game->map->matriz[i] = NULL;
		game->map->matriz[i] = create_spaced_line(matriz_dup[i], big_line - 1);
		i ++;
	}
	ft_free_matriz(matriz_dup);
}

/**
 * @attention Support function to make_map_rectangle();
 * @brief Puts spaces after '\n' or '\n' if necessary to make
 * all the lines in the matriz on the same size
 * @param big_line Size of the biggest line on the matriz 
 */
char	*create_spaced_line(char *line, int big_line)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char) * (big_line + 1));
	if (!ret)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		ret[j] = line[i];
		i ++;
		j ++;
	}
	while (j < big_line)
	{
		ret[j] = ' ';
		j ++;
	}
	ret[j] = '\0';
	return (ret);
}
