/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:54:58 by vivaccar          #+#    #+#             */
/*   Updated: 2024/10/07 14:02:10 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_bonus.h"

/**
 * @brief Rotates the player's direction and camera plane to the left.
 *
 * This function updates the player's direction vector and the camera plane
 * vector based on the given rotation speed. It applies a counterclockwise
 * rotation matrix to the current direction and plane vectors, effectively
 * simulating a leftward rotation of the player's view in a 2D space.
 *
*/
void	rotate_left(t_gm *game, double speed)
{
	double	old_dirx;
	double	old_diry;
	double	old_planex;
	double	old_planey;

	old_dirx = game->ray->dir_x;
	old_diry = game->ray->dir_y;
	game->ray->dir_x = old_dirx * cos(-speed) - old_diry * sin(-speed);
	game->ray->dir_y = old_dirx * sin(-speed) + old_diry * cos(-speed);
	old_planex = game->ray->plane_x;
	old_planey = game->ray->plane_y;
	game->ray->plane_x = old_planex * cos(-speed) - old_planey * sin(-speed);
	game->ray->plane_y = old_planex * sin(-speed) + old_planey * cos(-speed);
}

/**
 * @brief Rotates the player's direction and camera plane to the right.
 *
 * This function updates the player's direction vector and the camera plane
 * vector based on the given rotation speed. It applies a clockwise rotation 
 * matrix to the current direction and plane vectors, effectively simulating 
 * a rightward rotation of the player's view in a 2D space.
*/
void	rotate_right(t_gm *game, double speed)
{
	double	old_dirx;
	double	old_diry;
	double	old_planex;
	double	old_planey ;

	old_dirx = game->ray->dir_x;
	old_diry = game->ray->dir_y;
	game->ray->dir_x = old_dirx * cos(speed) - old_diry * sin(speed);
	game->ray->dir_y = old_dirx * sin(speed) + old_diry * cos(speed);
	old_planex = game->ray->plane_x;
	old_planey = game->ray->plane_y;
	game->ray->plane_x = old_planex * cos(speed) - old_planey * sin(speed);
	game->ray->plane_y = old_planex * sin(speed) + old_planey * cos(speed);
}
