/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:48:15 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/07 16:19:54 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

/**
 * @brief Get the texture HEIGHT and WIDTH
*/
void	get_txtr_size(int *height, int *width, t_gm *game)
{
	if (game->ray->side_hit == 1 && game->ray->ray_dir_y < 0)
	{
		*height = game->textr->txt_height[0];
		*width = game->textr->txt_width[0];
	}
	else if (game->ray->side_hit == 1 && game->ray->ray_dir_y > 0)
	{
		*height = game->textr->txt_height[1];
		*width = game->textr->txt_width[1];
	}
	else if (game->ray->side_hit == 0 && game->ray->ray_dir_x < 0)
	{
		*height = game->textr->txt_height[2];
		*width = game->textr->txt_width[2];
	}
	else
	{
		*height = game->textr->txt_height[3];
		*width = game->textr->txt_width[3];
	}
}

/**
 * @brief Calculates the height of the wall segment and draws the 
 * corresponding texture.
 * This function determines the height of the wall to be rendered 
 * based on the distance from the player to the wall 
 * (ray's wall distance). 
 * It calculates the appropriate texture coordinates and step size 
 * for rendering the texture on the wall. The function also 
 * identifies the side of the wall that was hit by the ray and calls
 * the drawing function with the correct texture based on the 
 * ray's direction and side hit.
 */

void	get_wall_height_and_draw(t_gm *game, t_ray *ray, int x)
{
	t_texture	*t;
	int			txt_w;
	int			txt_h;

	get_txtr_size(&txt_h, &txt_w, game);
	t = game->textr;
	t->r_line_len = (int)(HEIGHT / ray->wall_ppclr_dstc);
	t->txt_x = (int)(t->wall_hit_pos * (double)txt_w);
	t->step = 1.0 * txt_h / t->r_line_len;
	t->text_pos = (t->r_first_point - HEIGHT / 2 + t->r_line_len / 2) * t->step;
	get_render_points(game);
	get_wall_hit_pos(game);
	if (ray->side_hit == 1 && ray->ray_dir_y < 0)
		draw_texture(game, x, 0, txt_h);
	else if (ray->side_hit == 1 && ray->ray_dir_y > 0)
		draw_texture(game, x, 1, txt_h);
	else if (ray->side_hit == 0 && ray->ray_dir_x < 0)
		draw_texture(game, x, 2, txt_h);
	else
		draw_texture(game, x, 3, txt_h);
}

/**
 * @param g Game Structure,
 * @param x x position,
 * @param img_index img_index to be rendered.
 */
void	draw_texture(t_gm *game, int x, int img_index, int txt_h)
{
	int			y;
	int			color;
	t_texture	*t;

	t = game->textr;
	y = t->r_first_point;
	while (y < t->r_last_point)
	{
		t->txt_y = (int)t->text_pos & (txt_h - 1);
		t->text_pos += t->step;
		color = my_mlx_get_pixel(game, t->txt_x, t->txt_y, img_index);
		my_mlx_pixel_put(game->mlx, x, y, color);
		y++;
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
 * @brief Calculates the vertical points for rendering a wall segment.
 * This function computes `r_first_point` and `r_last_point` based on the 
 * wall height and screen dimensions, ensuring they remain within the 
 * screen boundaries. These points are crucial for correctly mapping 
 * the wall texture onto the display.
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
