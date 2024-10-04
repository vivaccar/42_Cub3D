/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:53:42 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/04 11:56:22 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

void	init_gun_struct(t_gm *game)
{
    t_texture *texture;

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

void draw_scaled_gun(t_gm *game, int scale_factor, int img_i)
{
    t_gun *g;
    int color;

    g = game->gun;
    g->scaled_h = game->textr->txt_height[img_i] * scale_factor;
    g->scaled_w = game->textr->txt_width[img_i] * scale_factor;
    g->start_x = (WIDTH - g->scaled_w) / 2;
    g->start_y = (HEIGHT - game->gun->move) - g->scaled_h;
    g->new_y = 0;
    while (g->new_y < g->scaled_h) // Loop through each pixel in the scaled gun sprite
    {
        g->new_x = 0;
        while (g->new_x < g->scaled_w)
        {
            g->orig_x = g->new_x / scale_factor;
            g->orig_y = g->new_y / scale_factor;
            color = my_mlx_get_pixel(game, g->orig_x, g->orig_y, img_i);
            if ((color & 0x00FFFFFF) != 0) //only prints if not transparent
                my_mlx_pixel_put(game->mlx, g->start_x + g->new_x,
                                    g->start_y + g->new_y, color);
            g->new_x ++;
        }
        g->new_y++;
    }
}

