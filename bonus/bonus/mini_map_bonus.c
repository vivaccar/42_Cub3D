/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:25:05 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/07 13:04:52 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_bonus.h"

/**
 * Renders the entire mini-map based on the game's map matrix.
 * It adjusts the tile size according to whether the mini-map button 
 * (m_pressed) is pressed (30 pixels if pressed, 10 otherwise) 
 * and iterates through the map matrix, calling render_mini_map for each tile.
 * Finally, it draws the player on the mini-map using render_mini_map_player.
 */
void	draw_mini_map(t_gm *game)
{
	int	i;
	int	j;

	i = 0;
	if (game->mm->m_pressed == 1)
		game->mm->tile_size = 30;
	else
		game->mm->tile_size = 10;
	while (game->map->matriz[i])
	{
		j = 0;
		while (game->map->matriz[i][j])
		{
			render_mini_map(game, j, i);
			j++;
		}
		i++;
	}
	render_mini_map_player(game);
}

/**
 * @brief Draws a tile on the mini-map based on the contents of the game map.
 * For each tile at coordinates (x, y), it checks the corresponding character
 * in the map's matrix: if it's a wall ('1'), it draws a white pixel; 
 * if it's a player or spawn point ('N', 'S', 'E', 'W', or '0'), 
 * it draws a red pixel. 
 * The size of each tile is determined by tile_size.
 */
void	render_mini_map(t_gm *game, int x, int y)
{
	int	i;
	int	j;
	int	ts;

	ts = game->mm->tile_size;
	i = 0;
	while (i < ts)
	{
		j = 0;
		while (j < ts)
		{
			if (game->map->matriz[y][x] == '1')
				my_mlx_pixel_put(game->mlx, (x * ts) + j, (y * ts) + i,
					0xFFFFFF);
			else if (ft_strchr("NSEW0", game->map->matriz[y][x]))
				my_mlx_pixel_put(game->mlx, (x * ts) + j, (y * ts) + i,
					0xFF0000);
			j++;
		}
		i++;
	}
}

/**
 * 
 * @brief draws the player as a small green circle on the mini-map. 
 * Depending on whether the mini-map button (m_pressed) is pressed, 
 * the player's radius is either 2 or 4. It uses a loop to fill in 
 * pixels within the circle's radius and places them at the player's 
 * current position on the mini-map.
 * circle calculus -> (x−xc​)**+(y−yc​)2<=r
 * xc​ and yc​ are the center coordinates of the circle (the player's position).
 * r is the radius of the circle.
 * x and y are the pixel coordinates you're calculating for 
 * each point in the circle.
 */

void	render_mini_map_player(t_gm *game)
{
	int	radius;
	int	x;
	int	y;

	if (!game->mm->m_pressed)
		radius = 2;
	else
		radius = 5;
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
			{
				my_mlx_pixel_put(game->mlx,
					(game->ray->plyr_x * game->mm->tile_size) + x,
					(game->ray->plyr_y * game->mm->tile_size) + y, 0x00FF00);
			}
			x ++;
		}
		y ++;
	}
}
