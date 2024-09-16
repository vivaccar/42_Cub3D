/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:49:58 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/10 19:20:34 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/**
 * @brief init the mlx library
*/
int	run_mlx(t_gm *game)
{
	game->mlx = malloc(sizeof(t_mlx));
	if (!game->mlx)
		return (err_msg("Error allocating mlx", EXIT_FAILURE));
	
	game->mlx->cnt = mlx_init();
	if (!game->mlx->cnt)
	{
		//free game->mlx
		return (err_msg("mlx_init failed", EXIT_FAILURE));
	}

	game->mlx->wnd = mlx_new_window(game->mlx->cnt, 1000, 1000, "Cub3d");
	if (!game->mlx->wnd)
	{
		//free game->mlx
		return (err_msg("mlx_new_window failed", EXIT_FAILURE));
	}
	
	mlx_loop(game->mlx->cnt);
	return (EXIT_SUCCESS);
}
