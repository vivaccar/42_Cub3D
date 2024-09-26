/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:36:02 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/26 15:22:46 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	add_new_door(int y, int x, t_doors **doors)
{
	t_doors *new;
	t_doors	*tmp;

	new = malloc(sizeof(t_doors));
	if (!new)
		return ; /// fazer funcao que libera memoria e da exit
	new->door_y = y;
	new->door_x = x;
	new->is_open = 0;
	new->next = NULL;
	if (*doors == NULL)
		*doors = new;
	else
	{
		tmp = *doors;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	find_doors(t_gm *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->matriz[i])
	{
		j = 0;
		while (game->map->matriz[i][j])
		{
			if (game->map->matriz[i][j] == 'D')
				add_new_door(i, j, &game->doors);
			j++;
		}
		i++;
	}
}

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
	if (!is_texture_and_color_valid(game, cub)
		|| !is_openble_file(game->map->ntex, NULL, 4)
		|| !is_openble_file(game->map->stex, NULL, 4)
		|| !is_openble_file(game->map->etex, NULL, 4)
		|| !is_openble_file(game->map->wtex, NULL, 4))
		return (ft_free_matriz(cub), EXIT_FAILURE);
	extract_map(game, cub);
	if (!is_map_valid(game))
		return (ft_free_matriz(cub), EXIT_FAILURE);
	ft_free_matriz(cub);
	find_doors(game);
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
