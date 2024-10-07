/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:53:42 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/07 13:04:48 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_bonus.h"

/**
 * @brief Initializes a gun structure (t_gun) for the game.
 * It allocates memory for the gun, checks for allocation success,
 * clears the allocated memory, and sets the texture pointer and 
 * movement speed for the gun. 
 * If memory allocation fails, it displays an error message.
 */
void	init_gun_struct(t_gm *game)
{
	t_texture	*texture;

	texture = game->textr;
	game->gun = malloc(sizeof(t_gun));
	if (!game->gun)
	{
		ft_err_msg("Error allocating gun struct", 1);
		return ;
	}
	ft_bzero(game->gun, sizeof(t_gun));
	game->gun->t = texture;
	game->gun->move = 17;
}

/**
 * @brief Handles the rendering of the gun on the screen.
 * If the gun is firing (indicated by fire being between 1 and 7)
 * it renders a scaled version of the gun firing
 * and increments the fire counter. 
 * Once the fire reaches 30, it resets to 0.
 * If the gun is not firing, it renders a not firing sprite.
 * Additionally, it always calls render_aim to display the aiming reticle.
 */
void	draw_gun(t_gm *game)
{
	if (game->gun->fire > 0 && game->gun->fire <= 7)
	{
		render_scaled_gun(game, 3, 5);
		game->gun->fire ++;
		if (game->gun->fire == 30)
			game->gun->fire = 0;
	}
	else
		render_scaled_gun(game, 3, 4);
	render_aim(game);
}

/**
 * @brief Renders a scaled image of the gun on the screen. 
 * It calculates the dimensions of the scaled gun based on a 
 * given scale_factor and the original texture size, 
 * determining where to start drawing it on the screen. 
 * It then loops through each pixel of the scaled gun, 
 * retrieves the corresponding color from the original texture, 
 * and draws the pixel on the screen if it is not transparent.
 *  This creates the effect of displaying the gun at a larger size.
 */
void	render_scaled_gun(t_gm *game, int scale_factor, int img_i)
{
	t_gun	*g;
	int		color;

	g = game->gun;
	g->scaled_h = game->textr->txt_height[img_i] * scale_factor;
	g->scaled_w = game->textr->txt_width[img_i] * scale_factor;
	g->start_x = (WIDTH - g->scaled_w) / 2;
	g->start_y = (HEIGHT - game->gun->move) - g->scaled_h;
	g->new_y = 0;
	while (g->new_y < g->scaled_h)
	{
		g->new_x = 0;
		while (g->new_x < g->scaled_w)
		{
			g->orig_x = g->new_x / scale_factor;
			g->orig_y = g->new_y / scale_factor;
			color = my_mlx_get_pixel(game, g->orig_x, g->orig_y, img_i);
			if ((color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(game->mlx, g->start_x + g->new_x,
					g->start_y + g->new_y, color);
			g->new_x ++;
		}
		g->new_y++;
	}
}

/**
 * @brief Displays the aiming reticle on the screen. 
 * It calculates the starting position to center the reticle image,
 * then iterates over each pixel of the reticle's texture index[6].
 * For each pixel, it retrieves the color from the texture and draws 
 * it on the screen if it is not transparent, effectively rendering 
 * the aiming reticle in the center of the screen.
 */
void	render_aim(t_gm *game)
{
	int	color;
	int	x;
	int	y;
	int	start_x;
	int	start_y;

	start_x = (WIDTH - game->textr->txt_width[6]) / 2;
	start_y = (HEIGHT - game->textr->txt_height[6]) / 2;
	y = 0;
	while (y < game->textr->txt_height[6])
	{
		x = 0;
		while (x < game->textr->txt_width[6])
		{
			color = my_mlx_get_pixel(game, x, y, 6);
			if ((color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(game->mlx, start_x + x, start_y + y, color);
			x ++;
		}
		y ++;
	}
}
