/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:45:44 by vivaccar          #+#    #+#             */
/*   Updated: 2024/10/04 15:03:28 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_bonus.h"

/**
 * @brief places a pixel of a specified color at the coordinates (x, y) 
 * in an image represented by the mlx structure. It calculates the memory 
 * address for the pixel's position in the image data and stores the color 
 * value at that location.
 */
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/**
 * @brief retrieves the color of a specific pixel from a texture in a game. 
 * It checks if the given coordinates (x, y) are within the texture's 
 * dimensions, calculates the pixel's memory offset, and returns the 
 * color value at that offset from the texture data. 
 * If the coordinates are out of bounds, it returns 0.
 */
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
	data_adr = mlx_get_data_addr(t->texture[index], &t->bits_per_pixel,
			&t->line_len, &t->endian);
	offset = (y * t->line_len) + (x * (t->bits_per_pixel / 8));
	return (*(int *)(data_adr + offset));
}

/**
 * @note Called on raycaster_bonus()
 * @brief fills the game window with a ceiling color (for the upper half) 
 * and a floor color (for the lower half). It iterates through each pixel, 
 * setting the pixel color based on its vertical position (using hex colors
 *  stored in the game map).
 */
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
