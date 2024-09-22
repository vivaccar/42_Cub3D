/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:25:05 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/22 18:23:14 by aconceic         ###   ########.fr       */
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

void	render_mini_map_pl_dir(t_gm *game)
{
   (void)game;
}


