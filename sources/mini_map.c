/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:25:05 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/30 11:05:26 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void draw_mini_map(t_gm *game)
{
	int i;
	int j;

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
 * @brief tl = TILE_SIZE
 */
void render_mini_map(t_gm *game, int x, int y)
{
	int i;
	int j;
	int ts;

	ts = game->mm->tile_size;
	i = 0;
	while (i < ts)
	{
		j = 0;
		while (j < ts)
		{
			if (game->map->matriz[y][x] == '1')
				my_mlx_pixel_put(game->mlx, (x * ts) + j, (y * ts) + i, 0xFFFFFF);
			else if (ft_strchr("NSEW0", game->map->matriz[y][x]))
				my_mlx_pixel_put(game->mlx, (x * ts) + j, (y * ts) + i, 0xFF0000);
			j++;
		}
		i++;
	}
}

/**
 * circle calculus -> (x−xc​)**+(y−yc​)2<=r
 * xc​ and yc​ are the center coordinates of the circle (the player's position).
 * r is the radius of the circle.
 * x and y are the pixel coordinates you're calculating for each point in the circle.
 */
void render_mini_map_player(t_gm *game)
{
	int radius;
	int x;
	int y;

	if (!game->mm->m_pressed)
		radius = 2;
	else
		radius = 4;
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)// Check if the point is inside the circle
			{
				my_mlx_pixel_put(game->mlx, (game->ray->plyr_x * game->mm->tile_size) + x,
					(game->ray->plyr_y * game->mm->tile_size) + y, 0x00FF00);
			}  	
			x ++;
		}
		y ++;
	}
	render_mini_map_pl_dir(game);
}

/**
 * Render Rays 
 */
void render_mini_map_pl_dir(t_gm *game)
{
	int ray_count = 100; // Number of rays to draw for FOV
	double fov = 66 * (M_PI / 180); // FOV in radians (e.g., 60 degrees)
	double ray_step = fov / ray_count; // Step between each ray
	double start_angle = atan2(game->ray->dir_y, game->ray->dir_x) - fov / 2; // Start angle of FOV

	for (int i = 0; i < ray_count; i++)
	{
		double ray_angle = start_angle + i * ray_step;

		// Calculate ray direction based on the angle
		double ray_dir_x = cos(ray_angle);
		double ray_dir_y = sin(ray_angle);

		// Initial position (player's position on the minimap)
		double ray_pos_x = game->ray->plyr_x;
		double ray_pos_y = game->ray->plyr_y;

		// Small step size for drawing the ray (in pixel increments)
		double step_size = 0.1; // Adjust this for finer lines (smaller = smoother)
		
		int hit = 0;
		while (!hit)
		{
			// Advance the ray in small steps along the direction vector
			ray_pos_x += ray_dir_x * step_size;
			ray_pos_y += ray_dir_y * step_size;

			// Convert the current ray position to minimap pixels
			int pixel_x = (int)(ray_pos_x * game->mm->tile_size);
			int pixel_y = (int)(ray_pos_y * game->mm->tile_size);

			// Draw the pixel on the minimap
			my_mlx_pixel_put(game->mlx, pixel_x, pixel_y, 0x00FF00); // Green ray

			// Check if we hit a wall
			if (game->map->matriz[(int)ray_pos_y][(int)ray_pos_x] == '1' ||
				game->map->matriz[(int)ray_pos_y][(int)ray_pos_x] == ' ')
			{
				hit = 1; // Wall hit, stop the ray
			}
		}
	}
}
