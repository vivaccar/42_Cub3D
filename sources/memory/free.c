/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:11:37 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/03 11:24:22 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	free_game(t_gm *game, int to_free)
{
	int	i;

	i = 0;
	free_map(game->map);
	free(game->map);
	free(game->ray);
	if (to_free)
	{
		free(game->textr);
		free(game->mlx);
	}
}

void	free_mlx(t_mlx *mlx, t_gm *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->textr->wall_texture[i])
			mlx_destroy_image(game->mlx->cnt, game->textr->wall_texture[i]);
		i++;
	}
	free(game->textr);
	mlx_destroy_window(mlx->cnt, mlx->wnd);
	mlx_destroy_image(mlx->cnt, mlx->img);
	mlx_destroy_display(mlx->cnt);
	free(mlx->cnt);
	free(mlx);
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
