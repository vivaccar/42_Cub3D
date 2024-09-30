/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:11:37 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/30 14:25:22 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	free_game(t_gm *game)
{
	int	i;

	i = 0;
	free_map(game->map);
	free(game->map);
	free(game->mm);
	free(game->ray);
	free(game->mlx);
	free(game->textr);
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
	mlx_destroy_window(mlx->cnt, mlx->wnd);
	mlx_destroy_image(mlx->cnt, mlx->img);
	mlx_destroy_display(mlx->cnt);
	free(mlx->cnt);
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
