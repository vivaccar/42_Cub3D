/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:27:20 by vivaccar          #+#    #+#             */
/*   Updated: 2024/10/03 11:04:09 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	close_cub(t_gm *game)
{
	free_game(game, 0);
	free_mlx(game->mlx, game);
	return (exit(0), 0);
}
