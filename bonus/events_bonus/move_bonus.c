/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:23:40 by vivaccar          #+#    #+#             */
/*   Updated: 2024/10/03 13:10:44 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_bonus.h"

bool	can_player_move(t_gm *game, int new_x, int new_y)
{
	if (game->map->matriz[(int)game->ray->plyr_y][new_x] == '1')
		return (false);
	if (game->map->matriz[new_y][(int)game->ray->plyr_x] == '1')
		return (false);
	if (game->map->matriz[new_y][new_x] == '1')
		return (false);
	return (true);
}

void	move_up(t_gm *game)
{
	double	new_x;
	double	new_y;

	new_x = game->ray->plyr_x + (game->ray->dir_x * game->ray->mov_speed);
	new_y = game->ray->plyr_y + (game->ray->dir_y * game->ray->mov_speed);
	if (can_player_move(game, new_x, new_y))
	{
		game->ray->plyr_x = new_x;
		game->ray->plyr_y = new_y;
	}
}

void	move_down(t_gm *game)
{
	double	new_x;
	double	new_y;

	new_x = game->ray->plyr_x - (game->ray->dir_x * game->ray->mov_speed);
	new_y = game->ray->plyr_y - (game->ray->dir_y * game->ray->mov_speed);
	if (can_player_move(game, new_x, new_y))
	{
		game->ray->plyr_x = new_x;
		game->ray->plyr_y = new_y;
	}
}

void	move_left(t_gm *game)
{
	double	new_x;
	double	new_y;

	new_x = game->ray->plyr_x - (game->ray->plane_x * game->ray->mov_speed);
	new_y = game->ray->plyr_y - (game->ray->plane_y * game->ray->mov_speed);
	if (can_player_move(game, new_x, new_y))
	{
		game->ray->plyr_x = new_x;
		game->ray->plyr_y = new_y;
	}
}

void	move_right(t_gm *game)
{
	double	new_x;
	double	new_y;

	new_x = game->ray->plyr_x + (game->ray->plane_x * game->ray->mov_speed);
	new_y = game->ray->plyr_y + (game->ray->plane_y * game->ray->mov_speed);
	if (can_player_move(game, new_x, new_y))
	{
		game->ray->plyr_x = new_x;
		game->ray->plyr_y = new_y;
	}
}
