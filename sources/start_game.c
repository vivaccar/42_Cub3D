/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:09:49 by vivaccar          #+#    #+#             */
/*   Updated: 2024/09/24 15:25:50 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int get_pixel_color(t_gm *game, int x, int y, int index)
{
    char *data_adr;
	int offset;
	int pixel;
	
	data_adr =  mlx_get_data_addr(game->textr->wall_texture[index],
		&game->textr->bits_per_pixel, &game->textr->line_length,
		&game->textr->endian);

	offset = (y * game->textr->line_length) + (x * (game->textr->bits_per_pixel / 8));
	pixel = *(int *)(data_adr + offset);
	return (pixel);
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
				my_mlx_pixel_put(mlx, x, y, 0x000000);
			else
				my_mlx_pixel_put(mlx, x, y, 0xC0C0C0);
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