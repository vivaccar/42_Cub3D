/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:29:26 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/02 16:24:29 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_bonus.h"

int	close_cub(t_gm *game)
{
	free_game(game);
	free_mlx(game->mlx, game);
	return (exit(0), 0);
}
