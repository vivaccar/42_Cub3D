/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:54:58 by vivaccar          #+#    #+#             */
/*   Updated: 2024/09/23 14:55:57 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	rotate_left(t_gm *game)
{
	(void)game;
	printf("KEYLEFT PRESSED\n");
	double old_dirx = game->ray->dirX;
	double old_diry = game->ray->dirY;  // Save both components before modifying
	
	// Apply rotation to the direction vector
	printf("ray dirx: %f\n", game->ray->dirX);
	printf("ray diry: %f\n", game->ray->dirY);

	game->ray->dirX = old_dirx * cos(-game->ray->mov_speed) - old_diry * sin(-game->ray->mov_speed);
	game->ray->dirY = old_dirx * sin(-game->ray->mov_speed) + old_diry * cos(-game->ray->mov_speed);
	printf("ray dirx: %f\n", game->ray->dirX);
	printf("ray diry: %f\n", game->ray->dirY);

	//exit(0);
	double old_planex = game->ray->plane_x;
	double old_planey = game->ray->plane_y;  // Save both components before modifying
	
	// Apply rotation to the plane vector
	game->ray->plane_x = old_planex * cos(-game->ray->mov_speed) - old_planey * sin(-game->ray->mov_speed);
	game->ray->plane_y = old_planex * sin(-game->ray->mov_speed) + old_planey * cos(-game->ray->mov_speed);
}

void	rotate_right(t_gm *game)
{
	(void)game;
	printf("KEYLEFT PRESSED\n");
	double old_dirx = game->ray->dirX;
	double old_diry = game->ray->dirY;  // Save both components before modifying
	
	// Apply rotation to the direction vector
	printf("ray dirx: %f\n", game->ray->dirX);
	printf("ray diry: %f\n", game->ray->dirY);

	game->ray->dirX = old_dirx * cos(game->ray->mov_speed) - old_diry * sin(game->ray->mov_speed);
	game->ray->dirY = old_dirx * sin(game->ray->mov_speed) + old_diry * cos(game->ray->mov_speed);
	printf("ray dirx: %f\n", game->ray->dirX);
	printf("ray diry: %f\n", game->ray->dirY);

	//exit(0);
	double old_planex = game->ray->plane_x;
	double old_planey = game->ray->plane_y;  // Save both components before modifying
	
	// Apply rotation to the plane vector
	game->ray->plane_x = old_planex * cos(game->ray->mov_speed) - old_planey * sin(game->ray->mov_speed);
	game->ray->plane_y = old_planex * sin(game->ray->mov_speed) + old_planey * cos(game->ray->mov_speed);
}