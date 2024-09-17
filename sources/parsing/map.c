/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:40:39 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/17 20:16:22 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	extract_map(t_gm *game, char **scene)
{
	int	start;
	int	lines;

	start = find_starting_point(scene);
	lines = ft_matrizlen(&scene[start]);
	game->map->matriz = ft_matrizdup(&scene[start]);
	//ft_printf_matriz(game->map->matriz);
	/* for (int i = 0; game->map->matriz[i]; i++)
		printf("%s", game->map->matriz[i]); */
	(void)scene;
	(void)game;
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
