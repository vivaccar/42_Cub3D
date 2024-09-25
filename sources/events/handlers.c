/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:28:20 by vivaccar          #+#    #+#             */
/*   Updated: 2024/09/25 14:12:18 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	key_press_handler(int keycode, t_gm *game)
{
	(void)keycode;
	
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
	(void) game;
	static int old_x = WIDTH / 2;
	
	if (x < old_x && x < WIDTH / 2)
		rotate_left(game, game->ray->mov_speed / 3);
	else if (x > old_x && x > WIDTH / 2)
		rotate_right(game, game->ray->mov_speed / 3);
	old_x = x;
	printf("%i", x);
	printf("%i", y);
	return (0);	
}