/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:28:20 by vivaccar          #+#    #+#             */
/*   Updated: 2024/09/23 14:12:47 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	key_press_handler(int keycode, t_gm *game)
{
	(void)keycode;
	
	if (keycode == KEY_ESC)
		esc_close(game);
	else if (keycode == KEY_W)
		move_up(game);
	else if (keycode == KEY_S)
		move_down(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_D)
		move_right(game);
/* 	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		rotate(game, keycode); */
	else if (keycode == KEY_M)
		game->mm->m_pressed = !game->mm->m_pressed;
	return (0);
}