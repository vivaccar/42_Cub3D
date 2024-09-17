/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:11:37 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/17 20:10:07 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	free_game(t_gm *game)
{
	free(game->mlx);//This we will need to destroy after
	free(game->window);
	free_map(game->map); //incomplete function
	free(game->map);//This we will need to clean inside, including close the fd
}

void	free_map(t_map *map)
{
	free(map->stex);
	free(map->ntex);
	free(map->etex);
	free(map->wtex);
	free(map->f_color);
	free(map->c_color);
	ft_free_matriz(map->matriz);
}
