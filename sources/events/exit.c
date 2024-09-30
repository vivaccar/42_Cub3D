/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:27:20 by vivaccar          #+#    #+#             */
/*   Updated: 2024/09/30 14:20:31 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	close_cub(t_gm *game)
{
	free_mlx(game->mlx, game);
	free_game(game);
	return (exit(0), 0);
}
