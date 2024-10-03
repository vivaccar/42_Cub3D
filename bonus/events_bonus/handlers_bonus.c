/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:28:20 by vivaccar          #+#    #+#             */
/*   Updated: 2024/10/03 19:16:41 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_bonus.h"

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
	else if (keycode == KEY_SHIFT)
		game->textr->gun_fire = 1;
	return (0);
}

int	mouse_handler(int x, int y, t_gm *game)
{
	static int	old_x = WIDTH / 2;

	(void) y;
	if (x < old_x) //&& x < WIDTH / 2 && x > 5)
		rotate_left(game, game->ray->mov_speed / 3);
	else if (x > old_x) //&& x > WIDTH / 2 && x < WIDTH - 5)
		rotate_right(game, game->ray->mov_speed / 3);
	old_x = x;
	return (0);
}

int	mouse_fire(int mousecode, int x, int y, void *param)
{
	(void)mousecode;
	(void)x;
	(void)y;
	t_gm *game;

	game = (t_gm *)param;
	if (!game->textr->gun_fire)
		return (EXIT_FAILURE);
	game->textr->gun_fire = 1;
	return (EXIT_SUCCESS);
}

