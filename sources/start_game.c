/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:09:49 by vivaccar          #+#    #+#             */
/*   Updated: 2024/09/16 16:14:24 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void    start_game(t_gm *game)
{
	// init to test 
	game->map->matriz = ft_calloc(sizeof(char **), 25);
	int i = 0;
	game->map->matriz[i] = ft_strdup("1111111111111111111111111");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000111100000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("10000000N0000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1000000000000000000000001");
	game->map->matriz[i] = ft_strdup("1111111111111111111111111");
	game->map->plyr_dir = 'N';
	if (game->map->plyr_dir == 'N')
	{
		game->map->plane_x = 0.66;
		game->map->plane_y = 0;
	}
	if (game->map->plyr_dir == 'S')
	{
		game->map->plane_x = -0.66;
		game->map->plane_y = 0;
	}
	if (game->map->plyr_dir == 'W')
	{
		game->map->plane_x = 0;
		game->map->plane_y = 0.66;
	}
	if (game->map->plyr_dir == 'E')
	{
		game->map->plane_x = 0;
		game->map->plane_y = -0.66;
	}
}

