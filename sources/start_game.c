/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:09:49 by vivaccar          #+#    #+#             */
/*   Updated: 2024/09/20 16:51:56 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_floor_ceiling(t_gm *game, t_mlx *mlx)
{
	int	y;
	int x;
	(void) game;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				my_mlx_pixel_put(mlx, x, y, game->map->cc_hex);
			else
				my_mlx_pixel_put(mlx, x, y, game->map->fc_hex);
			x++;				
		}
		y++;
	}
}


void    start_positions(t_gm *game)
{
	game->ray->plyr_x = game->map->plyr_x;
	game->ray->plyr_y = game->map->plyr_y;
	if (game->map->plyr_dir == 'N')
	{
		game->ray->plane_x = 0.66;
		game->ray->plane_y = 0;
		game->ray->dirX = 0.0;
		game->ray->dirY = -1.0;
	}
	else if (game->map->plyr_dir == 'S')
	{
		game->ray->plane_x = -0.66;
		game->ray->plane_y = 0;
		game->ray->dirX = 0.0;
		game->ray->dirY = 1.0;
	}
	else if (game->map->plyr_dir == 'W')
	{
		game->ray->plane_x = 0;
		game->ray->plane_y = -0.66;
		game->ray->dirX = -1.0;
		game->ray->dirY = 0.0;
	}
	else if (game->map->plyr_dir == 'E')
	{
		game->ray->plane_x = 0;
		game->ray->plane_y = 0.66;
		game->ray->dirX = 1.0;
		game->ray->dirY = 0.0;
	}
}


// plye_x e plyr_y --> DEFINEM A POSICAO DO JOGADOR NA MATRIZ;
// plane_x e plane_y --> DEFINEM O PLANO DE PROJECAO DA CAMERA DO JOGADOR
// dirX e dirY ---> VETORES DE DIRECAO;
// 