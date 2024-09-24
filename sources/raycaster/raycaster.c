/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:10:21 by vivaccar          #+#    #+#             */
/*   Updated: 2024/09/24 18:28:05 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

/**
 * @param g Game Structure,
 * @param s Starting point,
 * @param e Ending point,
 * @param c Color.
 */
void    draw_texture(t_gm *g, int s, int e, int c)
{
	(void)g;
	(void)s;
	(void)e;
	(void)c;
	
}
void    draw_vertical_line(int x, int draw_start, int draw_end, int color, t_mlx *mlx)
{
	while (draw_start <= draw_end)
	{
		my_mlx_pixel_put(mlx, x, draw_start, color);
		draw_start++;
	}
}

void    rays_direction(t_ray *ray, int x)
{
    ray->cam_x = 2 * x / (double)WIDTH - 1;
    ray->ray_dir_x = ray->dirX + ray->plane_x * ray->cam_x;
    ray->ray_dir_y = ray->dirY + ray->plane_y * ray->cam_x;       
}

void    delta_dstc(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dstc_x = INT_MAX;
	else
		ray->delta_dstc_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dstc_y = INT_MAX;
	else
		ray->delta_dstc_y = fabs(1 / ray->ray_dir_y);
}

void    step_increment(t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dstc_x = (ray->plyr_x - ray->map_x) * ray->delta_dstc_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dstc_x = (ray->map_x + 1.0 - ray->plyr_x) * ray->delta_dstc_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dstc_y = (ray->plyr_y - ray->map_y) * ray->delta_dstc_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dstc_y = (ray->map_y + 1 - ray->plyr_y) * ray->delta_dstc_y;
	}
}

void    launch_ray(t_ray *ray, t_map *map)
{
	int hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dstc_x < ray->side_dstc_y)
		{
			ray->side_dstc_x += ray->delta_dstc_x;
			ray->map_x += ray->step_x;
			ray->side_hit = 0;
		}
		else
		{
			ray->side_dstc_y += ray->delta_dstc_y;
			ray->map_y += ray->step_y;
			ray->side_hit = 1;
		}
		if (map->matriz[ray->map_y][ray->map_x] == '1')
		{
			//printf("Wall hitted X = %i, Y = %i\n", ray->map_x, ray->map_y);
			hit = 1;
		}    
	}
}

void get_wall_height_and_draw(t_gm *game, t_ray *ray, int x)
{
    int line_size;
    int first_point;
    int last_point;
    int color;
    int texture_height = 128;
    int texture_width = 128;

    // Calculate perpendicular distance to the wall
    ray->wall_dstc = ray->side_dstc_y - ray->delta_dstc_y;
	if (ray->side_hit == 0)	
		ray->wall_dstc = ray->side_dstc_x - ray->delta_dstc_x;

    // Calculate the line size on screen
    line_size = (int)(HEIGHT / ray->wall_dstc);

    // Calculate start and end points of the line
    first_point = -line_size / 2 + HEIGHT / 2;
    if (first_point < 0)
        first_point = 0;
    last_point = line_size / 2 + HEIGHT / 2;
    if (last_point >= HEIGHT)
        last_point = HEIGHT - 1;

    // Calculate where the wall was hit (wall_x)
    double wall_x;
    if (ray->side_hit == 0)
        wall_x = ray->plyr_y + ray->wall_dstc * ray->ray_dir_y; // Hit vertical wall
    else
        wall_x = ray->plyr_x + ray->wall_dstc * ray->ray_dir_x; // Hit horizontal wall

    wall_x -= floor(wall_x);  // Get the fractional part of the hit position

    // x coordinate on the texture
    int textX = (int)(wall_x * (double)texture_width);
    double step = 1.0 * texture_height / line_size;
    double textPos = (first_point - HEIGHT / 2 + line_size / 2) * step;

    // Check which wall was hit and calculate the texture accordingly
    if (ray->side_hit == 1 && ray->ray_dir_y < 0) // South-facing wall
    {
        textX = texture_width - textX - 1; // Flip texture for south-facing wall

        // Loop through each y-coordinate of the line and fetch the texture color
        for (int y = first_point; y < last_point; y++)
        {
            int textY = (int)textPos & (texture_height - 1);  // Texture Y coordinate
            textPos += step;

            // Get the pixel color from the texture (adjust to how you fetch it)
            color = get_pixel_color(game, textX, textY, 0);
            
            // Draw the pixel on the screen
            draw_vertical_line(x, y, y, color, game->mlx);
        }
    }
    else if (ray->side_hit == 1 && ray->ray_dir_y > 0) // North-facing wall
    {
        textX = texture_width - textX - 1; // Flip texture for north-facing wall
        
        // Loop through each y-coordinate of the line and fetch the texture color
        for (int y = first_point; y < last_point; y++)
        {
            int textY = (int)textPos & (texture_height - 1);
            textPos += step;
            
            color = get_pixel_color(game, textX, textY, 1);
            draw_vertical_line(x, y, y, color, game->mlx);
        }
    }
    else if (ray->side_hit == 0 && ray->ray_dir_x < 0) // East-facing wall
    {
        textX = texture_width - textX - 1; // Flip texture for east-facing wall
        
        // Loop through each y-coordinate of the line and fetch the texture color
        for (int y = first_point; y < last_point; y++)
        {
            int textY = (int)textPos & (texture_height - 1);
            textPos += step;
            
            color = get_pixel_color(game, textX, textY, 2);
            draw_vertical_line(x, y, y, color, game->mlx);
        }
    }
    else // West-facing wall
    {
        // No need to flip for west-facing wall
        
        // Loop through each y-coordinate of the line and fetch the texture color
        for (int y = first_point; y < last_point; y++)
        {
            int textY = (int)textPos & (texture_height - 1);
            textPos += step;
            
            color = get_pixel_color(game, textX, textY, 3);
            draw_vertical_line(x, y, y, color, game->mlx);
        }
    }
}


int raycaster(t_gm *game)
{
	int x;

	x = 0;
	draw_floor_ceiling(game, game->mlx);
	while (x < WIDTH)
	{
		game->ray->map_x = (int)game->ray->plyr_x;
		game->ray->map_y = (int)game->ray->plyr_y;
		rays_direction(game->ray, x);
		delta_dstc(game->ray);
		step_increment(game->ray);
		launch_ray(game->ray, game->map);
		get_wall_height_and_draw(game, game->ray, x);
		x++;
	}
	draw_mini_map(game);
	mlx_put_image_to_window(game->mlx->cnt, game->mlx->wnd, game->mlx->img, 0, 0);
	return 0;
}
