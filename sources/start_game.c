/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:09:49 by vivaccar          #+#    #+#             */
/*   Updated: 2024/09/16 15:38:55 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void start_game(t_gm *game)
{
    // init to test 
    game->map->coordinates = ft_calloc(sizeof(char **), 25);
    int i = 0;
    game->map->coordinates[i] = ft_strdup("1111111111111111111111111");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000111100000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("10000000N0000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1000000000000000000000001");
    game->map->coordinates[i] = ft_strdup("1111111111111111111111111");
    game->map->player_direction = 'N';
    if (game->map->player_direction == 'N')
	{
		game->map->plane_x = 0.66;
		game->map->plane_y = 0;
	}
	if (game->map->player_direction == 'S')
	{
		game->map->plane_x = -0.66;
		game->map->plane_y = 0;
	}
	if (game->map->player_direction == 'W')
	{
		game->map->plane_x = 0;
		game->map->plane_y = 0.66;
	}
	if (game->map->player_direction == 'E')
	{
		game->map->plane_x = 0;
		game->map->plane_y = -0.66;
	}
}

