/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:49:58 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:33:27 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/**
 * @brief Start main game struct
 * allocate memory and init values to NULL or 0;
 */
int	init_game_struct(t_gm *game, int argc, char **argv)
{
	ft_bzero(game, sizeof(t_gm));
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (err_msg("Error allocating map struct", EXIT_FAILURE));
	game->mlx = malloc(sizeof(t_mlx));
	if (!game->mlx)
	{
		free(game->map);
		return (err_msg("Error allocating mlx", EXIT_FAILURE));
	}
	game->window = malloc(sizeof(t_window));
	if (!game->window)
	{
		free(game->map);
		free(game->mlx);
		return (err_msg("Error allocating windows", EXIT_FAILURE));
	}
	game->argc_cpy = argc;
	game->argv_cpy = ft_matrizdup(argv);
	return (EXIT_SUCCESS);
}

/**
 * @brief init the mlx library
*/
int	run_mlx(t_gm *game)
{	
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
