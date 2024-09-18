/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:36:02 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/18 16:58:23 by vivaccar         ###   ########.fr       */
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
