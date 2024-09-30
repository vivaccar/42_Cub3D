/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:28:20 by vivaccar          #+#    #+#             */
/*   Updated: 2024/09/30 13:00:20 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	key_press_handler(int keycode, t_gm *game)
{
	if (keycode == KEY_ESC)
		close_cub(game);
	else if (keycode == KEY_W)
		move_up(game);
	else if (keycode == KEY_S)
		move_down(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_LEFT)
		rotate_left(game, game->ray->mov_speed);
	else if (keycode == KEY_RIGHT)
		rotate_right(game, game->ray->mov_speed);
	else if (keycode == KEY_M)
		game->mm->m_pressed = !game->mm->m_pressed;
	return (0);
}

int	mouse_handler(int x, int y, t_gm *game)
{
	(void) y;
	static int old_x = WIDTH / 2;
	
	if (x < old_x && x < WIDTH / 2 && x > 5)
		rotate_left(game, game->ray->mov_speed / 3);
	else if (x > old_x && x > WIDTH / 2 && x < WIDTH - 5)
		rotate_right(game, game->ray->mov_speed / 3);
	old_x = x;	
	return (0);	
}
