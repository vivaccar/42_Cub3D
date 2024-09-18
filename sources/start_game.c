/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:09:49 by vivaccar          #+#    #+#             */
/*   Updated: 2024/09/18 16:40:54 by vivaccar         ###   ########.fr       */
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


void    start_game(t_gm *game)
{
	// initializing main data to start raycasting 
/* 	game->map->matriz = ft_calloc(sizeof(char *), 25);
	game->map->matriz[0] = ft_strdup("1111111111111111111111111");
	game->map->matriz[1] = ft_strdup("1000000000000000000000001");
	game->map->matriz[2] = ft_strdup("1000000000000000000000001");
	game->map->matriz[3] = ft_strdup("1000000000000000000000001");
	game->map->matriz[4] = ft_strdup("1000000000000000000000001");
	game->map->matriz[5] = ft_strdup("1000000000000000000000001");
	game->map->matriz[6] = ft_strdup("1000000000000000000000001");
	game->map->matriz[7] = ft_strdup("1000000000000000000000001");
	game->map->matriz[9] = ft_strdup("1000000000000000000000001");
	game->map->matriz[10] = ft_strdup("1000000000000000000000001");
	game->map->matriz[11] = ft_strdup("1000000000000000000000001");
	game->map->matriz[12] = ft_strdup("1000000000000000000000001");
	game->map->matriz[13] = ft_strdup("1000000000000000000000001");
	game->map->matriz[14] = ft_strdup("1000000000000000000000001");
	game->map->matriz[15] = ft_strdup("1000000000000000000000001");
	game->map->matriz[16] = ft_strdup("1000000000000000000000001");
	game->map->matriz[17] = ft_strdup("1000000000000000000000001");
	game->map->matriz[18] = ft_strdup("1000000111110000000000001");
	game->map->matriz[19] = ft_strdup("1000000000000000000000001");
	game->map->matriz[20] = ft_strdup("1000000000000000000000001");
	game->map->matriz[21] = ft_strdup("1000000000000000000000001");
	game->map->matriz[22] = ft_strdup("1000000000000000000000001");
	game->map->matriz[23] = ft_strdup("1000000000N00000000000001");
	game->map->matriz[24] = ft_strdup("1111111111111111111111111");
	game->map->plyr_dir = 'N';
	game->map->plyr_x = 5.0;
	game->map->plyr_y = 5.0; */
	//game->map->ntex = game->map->nte;
/* 	game->map->stex = ft_strdup("textures/test2.xpm");
	game->map->etex = ft_strdup("textures/test3.xpm");
	game->map->wtex = ft_strdup("textures/test4.xpm"); */
	game->map->plyr_x = 15.0;
	game->map->plyr_y = 10.0;
	game->map->plyr_dir = 'N';
	game->map->dirX = 0.0;
	game->map->dirY = -1.0;
	if (game->map->plyr_dir == 'N')
	{
		game->map->plane_x = 0.66;
		game->map->plane_y = 0;
	}
	else if (game->map->plyr_dir == 'S')
	{
		game->map->plane_x = -0.66;
		game->map->plane_y = 0;
	}
	else if (game->map->plyr_dir == 'W')
	{
		game->map->plane_x = 0;
		game->map->plane_y = 0.66;
	}
	else if (game->map->plyr_dir == 'E')
	{
		game->map->plane_x = 0;
		game->map->plane_y = -0.66;
	}
}


// plye_x e plyr_y --> DEFINEM A POSICAO DO JOGADOR NA MATRIZ;
// plane_x e plane_y --> DEFINEM O PLANO DE PROJECAO DA CAMERA DO JOGADOR
// dirX e dirY ---> VETORES DE DIRECAO;
// 