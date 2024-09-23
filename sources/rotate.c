/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:02:22 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/23 14:06:44 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	rotate_left(t_gm *game)
{
	(void)game;
	printf("KEYLEFT PRESSED\n");
	double old_dirx = game->ray->dirX;
	double old_diry = game->ray->dirY;  // Save both components before modifying
	
	// Apply rotation to the direction vector
	game->ray->dirX *= old_dirx * cos(-0.40) - old_diry * sin(-0.40);
	game->ray->dirY = old_dirx * sin(-0.40) + old_diry * cos(-0.40);
	
	double old_planex = game->ray->plane_x;
	double old_planey = game->ray->plane_y;  // Save both components before modifying
	
	// Apply rotation to the plane vector
	game->ray->plane_x = old_planex * cos(-0.40) - old_planey * sin(-0.40);
	game->ray->plane_y = old_planex * sin(-0.40) + old_planey * cos(-0.40);
}

void	rotate_right(t_gm *game)
{
	(void)game;
	printf("KEYRIGHT PRESSED\n");
}