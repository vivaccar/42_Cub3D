/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:29:26 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/04 14:48:47 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_bonus.h"

/**
 * @note called on run_cub()
 * @brief Responsable to free pointers and exit the game
 * when called.
 */
int	close_cub(t_gm *game)
{
	free_game(game, 0);
	free_mlx(game->mlx, game);
	return (exit(0), 0);
}
