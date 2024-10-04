/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:48:15 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/04 15:16:45 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_bonus.h"

/**
 * @brief Calculates the height of the wall to be drawn on the screen based on 
 * the ray's perpendicular distance (wall_ppclr_dstc). It also determines the 
 * texture coordinates and the step size for texture mapping. Then, depending 
 * on which side of the wall the ray hit and the direction of the ray, it 
 * selects the appropriate texture to render the wall slice 
 * on the screen at position x.
 */
void	get_wall_height_and_draw(t_gm *game, t_ray *ray, int x)
{
	t_texture	*t;

	t = game->textr;
	t->r_line_len = (int)(HEIGHT / ray->wall_ppclr_dstc);
	t->txt_x = (int)(t->wall_hit_pos * (double)TXT_W);
	t->step = 1.0 * TXT_H / t->r_line_len;
	t->text_pos = (t->r_first_point - HEIGHT / 2 + t->r_line_len / 2) * t->step;
	get_render_points(game);
	get_wall_hit_pos(game);
	if (ray->side_hit == 1 && ray->ray_dir_y < 0)
		draw_texture(game, x, 0);
	else if (ray->side_hit == 1 && ray->ray_dir_y > 0)
		draw_texture(game, x, 1);
	else if (ray->side_hit == 0 && ray->ray_dir_x < 0)
		draw_texture(game, x, 2);
	else
		draw_texture(game, x, 3);
}

/**
 * @brief Renders a vertical slice of a texture onto the screen at position x.
 * It loops through the y-coordinates between r_first_point and r_last_point,
 * fetching the corresponding texture color for each pixel 
 * from the texture image (img_index), 
 * and places it onto the screen using my_mlx_pixel_put.
 */
void	draw_texture(t_gm *game, int x, int img_index)
{
	int			y;
	int			color;
	t_texture	*t;

	t = game->textr;
	y = t->r_first_point;
	while (y < t->r_last_point)
	{
		t->txt_y = (int)t->text_pos & (TXT_H - 1);
		t->text_pos += t->step;
		color = my_mlx_get_pixel(game, t->txt_x, t->txt_y, img_index);
		my_mlx_pixel_put(game->mlx, x, y, color);
		y ++;
	}
}

/**
 * @brief Calculates the exact fractional position on the wall 
 * where the ray hits. This is used to determine which 
 * part of the texture will be mapped onto the wall in the final rendering.
 */
void	get_wall_hit_pos(t_gm *game)
{
	t_ray		*r;
	t_texture	*t;

	r = game->ray;
	t = game->textr;
	if (r->side_hit == 0)
		t->wall_hit_pos = r->plyr_y + r->wall_ppclr_dstc * r->ray_dir_y;
	else
		t->wall_hit_pos = r->plyr_x + r->wall_ppclr_dstc * r->ray_dir_x;
	t->wall_hit_pos -= floor(t->wall_hit_pos);
}

/**
 * @brief calculates the starting (r_first_point) and ending (r_last_point) 
 * y-coordinates of a vertical line representing a wall to be rendered on 
 * the screen, ensuring they stay within the screen height (HEIGHT). 
 * These points define the portion of the wall slice to be drawn.
 */
void	get_render_points(t_gm *game)
{
	t_texture	*t;

	t = game->textr;
	t->r_first_point = -t->r_line_len / 2 + HEIGHT / 2;
	if (t->r_first_point < 0)
		t->r_first_point = 0;
	t->r_last_point = t->r_line_len / 2 + HEIGHT / 2;
	if (t->r_last_point >= HEIGHT)
		t->r_last_point = HEIGHT - 1;
}
