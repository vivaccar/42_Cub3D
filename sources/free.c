/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:11:37 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/25 13:48:56 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	free_game(t_gm *game)
{
	int	i = 0;
	
	free_map(game->map); //incomplete function
	free(game->map);//This we will need to clean inside, including close the fd
	free(game->mm);
	free(game->ray);
 	while (i < 4)
	{
		mlx_destroy_image(game->mlx->cnt, game->textr->wall_texture[i]);
		i++;
	}
	free(game->textr);
}

void	free_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->cnt, mlx->wnd);
	mlx_destroy_image(mlx->cnt, mlx->img);
	//free(mlx->addr);
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

