/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:28:20 by vivaccar          #+#    #+#             */
/*   Updated: 2024/10/04 14:47:26 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_bonus.h"

/**
 * @note called on run_cub()
 * @brief Function that redirect the specific keycode pressed
 * to the event of that keycode. 
 * Example : If press W -> will move up.
 * @attention All the keycode are declared as MACROS on the .h file;
 */
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
		game->gun->fire = 1;
	return (0);
}

/**
 * @note called on run_cub()
 * @brief Get the mouse position in x and y and chage the value
 * according to the moviment
 * if is on the left side of the map, rotate left. Else, rotate right.
 */
int	mouse_handler(int x, int y, t_gm *game)
{
	static int	old_x = WIDTH / 2;

	(void) y;
	if (x < old_x)
		rotate_left(game, game->ray->mov_speed / 3);
	else if (x > old_x)
		rotate_right(game, game->ray->mov_speed / 3);
	old_x = x;
	return (0);
}

/**
 * @note called on run_cub()
 * @brief Trigger the variable responsable for "shooting" the gun
 * useful note below(put together):
 * https://42born2code.slack.com/archives/CN9RHKQHW/
 * p1677429762961739?thread_ts=1677275183.646529&cid=CN9RHKQHW
 */
int	mouse_fire(int mousecode, int x, int y, void *param)
{
	t_gm	*game;

	(void)mousecode;
	(void)x;
	(void)y;
	game = (t_gm *)param;
	if (!game->gun->fire)
		return (EXIT_FAILURE);
	game->gun->fire = 1;
	return (EXIT_SUCCESS);
}
