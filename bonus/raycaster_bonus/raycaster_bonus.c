/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:10:21 by vivaccar          #+#    #+#             */
/*   Updated: 2024/10/04 15:36:53 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_bonus.h"

/**
 * @brief calculates the direction of a ray for a specific screen column x 
 * in a raycasting system, setting the ray's x and 
 * y directions (ray_dir_x, ray_dir_y) based on the camera position and 
 * the player's view.
 */
void	rays_direction(t_ray *ray, int x)
{
	ray->cam_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->cam_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->cam_x;
}

/**
 * @brief Calculates the delta distances (delta_dstc_x and delta_dstc_y)
 * for a ray in both the x and y directions.
 * These values represent the distance the ray travels along the x or y axis
 * before crossing a grid line. If the ray's direction is zero in either axis,
 * the corresponding delta distance is set to infinity (INT_MAX).
 */
void	delta_dstc(t_ray *ray)
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

/**
 * @brief Determines the step direction (step_x, step_y) and the initial 
 * side distances (side_dstc_x, side_dstc_y) for a ray in a raycasting system.
 * It adjusts these based on the ray's direction, setting the step to 1 or -1 
 * depending on whether the ray is moving in the positive or negative x 
 * and y directions, and calculates how far the ray has to travel to reach 
 * the next grid line.
 */
void	step_increment(t_ray *ray)
{
	t_ray	*r;

	r = ray;
	r->step_x = 1;
	r->side_dstc_x = (r->map_x + 1.0 - r->plyr_x) * r->delta_dstc_x;
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dstc_x = (r->plyr_x - r->map_x) * r->delta_dstc_x;
	}
	r->step_y = 1;
	r->side_dstc_y = (r->map_y + 1 - r->plyr_y) * r->delta_dstc_y;
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dstc_y = (r->plyr_y - r->map_y) * r->delta_dstc_y;
	}
}

/**
 * @brief  casts a ray through a 2D grid (map), checking for wall collisions.
 * It increments the ray's position step by step, comparing the distances to 
 * the next x and y grid lines (side_dstc_x and side_dstc_y), and advances the 
 * ray accordingly. When the ray hits a wall (represented by '1' in the map),
 * the loop stops, and the perpendicular wall dist (wall_ppclr_dstc) is updated
 */
void	launch_ray(t_ray *ray, t_map *map)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dstc_x < ray->side_dstc_y)
		{
			ray->side_dstc_x += ray->delta_dstc_x;
			ray->map_x += ray->step_x;
			ray->side_hit = 0;
			ray->wall_ppclr_dstc = ray->side_dstc_x - ray->delta_dstc_x;
		}
		else
		{
			ray->side_dstc_y += ray->delta_dstc_y;
			ray->map_y += ray->step_y;
			ray->side_hit = 1;
			ray->wall_ppclr_dstc = ray->side_dstc_y - ray->delta_dstc_y;
		}
		if (map->matriz[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

/**
 * @note called on run_cub()
 * Centers mouse in the window, Draws floor and ceiling,
 * Iterates over the width of the window and 
 * 1 -> calculates the player's current map position 
 * 2 -> Computes the direction of rays based on the player's position
 * 3 -> Determines the distance to the next map tile
 * 4 -> steps through the map to cast rays and detects wall intersections
 * 5 -> Calculates the wall height and renders it for each column of the screen
 * Draw mini-map and gun (with aim);
 * then render everything in the window.
 */
int	raycaster(t_gm *game)
{
	int	x;

	x = 0;
	mlx_mouse_move(game->mlx->cnt, game->mlx->wnd, WIDTH / 2, HEIGHT / 2);
	draw_floor_ceiling(game);
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
	draw_gun(game);
	mlx_put_image_to_window(game->mlx->cnt, game->mlx->wnd,
		game->mlx->img, 0, 0);
	return (EXIT_SUCCESS);
}
