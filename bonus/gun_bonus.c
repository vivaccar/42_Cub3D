/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:53:42 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/03 16:57:02 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

void draw_scaled_gun(t_gm *game, int scale_factor, int img_i)
{
    int orig_x;
    int orig_y;
    int new_x;
    int new_y;
    int start_x;
    int start_y;
    int color;
    int scaled_gun_w;
    int scaled_gun_h;

    // Calculate the new dimensions of the scaled gun
    scaled_gun_w = game->textr->txt_width[img_i] * scale_factor;
    scaled_gun_h = game->textr->txt_height[img_i] * scale_factor;

    // Calculate the starting position for the scaled gun
    start_x = (WIDTH - scaled_gun_w) / 2;
    start_y = (HEIGHT - game->textr->gun_mov) - scaled_gun_h;
    new_y = 0;
    // Loop through each pixel in the scaled gun sprite
    while (new_y < scaled_gun_h)
    {
        new_x = 0;
        while (new_x < scaled_gun_w)
        {
            orig_x = new_x / scale_factor;
            orig_y = new_y / scale_factor;

            // Get the pixel color from the original gun image
            color = my_mlx_get_pixel(game, orig_x, orig_y, img_i);  // Assuming 4 is the gun texture index

            // Skip transparent pixels (assuming transparency is represented by 0)
            if ((color & 0x00FFFFFF) != 0) // Only draw non-transparent pixels
            {
                // Draw the scaled pixel on the screen
                my_mlx_pixel_put(game->mlx, start_x + new_x, start_y + new_y, color);
            }
            new_x ++;
        }
        new_y++;
    }
}

