/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:11:37 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/25 19:57:50 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	free_game(t_gm *game)
{
	free(game->mlx);
	free_map(game->map);
	free(game->map);
	free(game->mm);
	free(game->ray);
}

void	free_mlx(t_mlx *mlx)
{
	free(mlx->wnd);
	free(mlx->img);
}

void	free_map(t_map *map)
{
	close(map->fd);
	free(map->stex);
	free(map->ntex);
	free(map->etex);
	free(map->wtex);
	free(map->fc_str);
	free(map->cc_str);
	ft_free_matriz(map->matriz);
}
