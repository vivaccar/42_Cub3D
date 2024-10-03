/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:29:51 by vivaccar          #+#    #+#             */
/*   Updated: 2024/10/03 15:00:12 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

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
	int			max_txt_width;
	int			max_txt_height;

	max_txt_height = game->textr->txt_height[index];
	max_txt_width = game->textr->txt_width[index];

	if (x >= max_txt_width || y >= max_txt_height)
		return (0);
	t = game->textr;
	data_adr = mlx_get_data_addr(t->wall_texture[index], &t->bits_per_pixel,
			&t->line_len, &t->endian);
	offset = (y * t->line_len) + (x * (t->bits_per_pixel / 8));
	return (*(int *)(data_adr + offset));
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
