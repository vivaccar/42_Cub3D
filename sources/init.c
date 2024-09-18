/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:49:58 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/18 14:53:57 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/**
 * @brief Start main game struct
 * allocate memory and init values to NULL or 0;
 */
int	init_game_struct(t_gm *game)
{
	ft_bzero(game, sizeof(t_gm));
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (ft_err_msg("Error allocating map struct", EXIT_FAILURE));
	init_map_struct(game);
	game->mlx = malloc(sizeof(t_mlx));
	if (!game->mlx)
	{
		free(game->map);
		return (ft_err_msg("Error allocating mlx", EXIT_FAILURE));
	}
	game->window = malloc(sizeof(t_window));
	if (!game->window)
	{
		free(game->map);
		free(game->mlx);
		return (ft_err_msg("Error allocating windows", EXIT_FAILURE));
	}
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
		return (ft_err_msg("mlx_init failed", EXIT_FAILURE));
	}

	game->mlx->wnd = mlx_new_window(game->mlx->cnt, WIDTH, HEIGHT, "Cub3d");
	if (!game->mlx->wnd)
	{
		//free game->mlx
		return (ft_err_msg("mlx_new_window failed", EXIT_FAILURE));
	}
	game->mlx->img = mlx_new_image(game->mlx->cnt, WIDTH, HEIGHT);
	game->mlx->addr = mlx_get_data_addr(game->mlx->img, &game->mlx->bits_per_pixel, &game->mlx->line_length, &game->mlx->endian);
	//draw_floor_ceiling(game, game->mlx);
	raycaster(game->map, game->mlx);
	mlx_put_image_to_window(game->mlx->cnt, game->mlx->wnd, game->mlx->img, 0, 0);
	mlx_loop(game->mlx->cnt);
	return (EXIT_SUCCESS);
}

/**
 * @brief Set the values of game->map to 0, NULL or some initial value.
 * The game->map was already allocated on init_game_struct()
 */
void	init_map_struct(t_gm *game)
{
	game->map->fd = 0;
	game->map->matriz = NULL;
	game->map->fc_str = NULL;
	game->map->cc_str = NULL;
	game->map->ntex = NULL;
	game->map->stex = NULL;
	game->map->etex = NULL;
	game->map->wtex = NULL;
	game->map->plyr_dir = '\0';
	game->map->plyr_x = 0.0;
	game->map->plyr_y = 0.0;
	game->map->plane_x = 0.0;
	game->map->plane_x = 0.0;
	game->map->fc_rgb[0] = 0;
	game->map->fc_rgb[1] = 0;
	game->map->fc_rgb[2] = 0;
	game->map->cc_rgb[0] = 0;
	game->map->cc_rgb[1] = 0;
	game->map->cc_rgb[2] = 0;
	game->map->fc_hex = 0;
	game->map->cc_hex = 0;
}
