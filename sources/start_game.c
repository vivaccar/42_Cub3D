/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:09:49 by vivaccar          #+#    #+#             */
/*   Updated: 2024/09/26 14:34:01 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

// plye_x e plyr_y --> DEFINEM A POSICAO DO JOGADOR NA MATRIZ;
// plane_x e plane_y --> DEFINEM O PLANO DE PROJECAO DA CAMERA DO JOGADOR
// dir_x e dir_y ---> VETORES DE DIRECAO;
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_get_pixel(t_gm *game, int x, int y, int index)
{
	char		*data_adr;
	t_texture	*t;
	int			offset;
	int			pixel;

	t = game->textr;
	data_adr = mlx_get_data_addr(t->wall_texture[index], &t->bits_per_pixel,
			&t->line_len, &t->endian);
	offset = (y * t->line_len) + (x * (t->bits_per_pixel / 8));
	pixel = *(int *)(data_adr + offset);
	return (pixel);
}

void	draw_floor_ceiling(t_gm *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				my_mlx_pixel_put(game->mlx, x, y, game->map->cc_hex);
			else
				my_mlx_pixel_put(game->mlx, x, y, game->map->fc_hex);
			x ++;
		}
		y++;
	}
}

void	start_player_position(t_gm *game)
{
	game->ray->plyr_x = game->map->plyr_x;
	game->ray->plyr_y = game->map->plyr_y;
	if (game->map->plyr_dir == 'N')
	{
		set_plane_positions(game, 0.66, 0.0);
		set_direction_positions(game, 0.0, -1.0);
	}
	else if (game->map->plyr_dir == 'S')
	{
		set_plane_positions(game, -0.66, 0.0);
		set_direction_positions(game, 0.0, 1.0);
	}
	else if (game->map->plyr_dir == 'W')
	{
		set_plane_positions(game, 0.0, -0.66);
		set_direction_positions(game, -1.0, 0.0);
	}
	else if (game->map->plyr_dir == 'E')
	{
		set_plane_positions(game, 0.0, 0.66);
		set_direction_positions(game, 1.0, 0.0);
	}
}

void	set_plane_positions(t_gm *game, double plane_x, double plane_y)
{
	game->ray->plane_x = plane_x;
	game->ray->plane_y = plane_y;
}

void	set_direction_positions(t_gm *game, double dir_x, double dir_y)
{
	game->ray->dir_x = dir_x;
	game->ray->dir_y = dir_y;
}
