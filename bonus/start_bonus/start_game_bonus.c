/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:09:49 by vivaccar          #+#    #+#             */
/*   Updated: 2024/10/04 15:38:03 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_bonus.h"

/**
 * @brief Init mlx library
*/
int	run_mlx(t_gm *game)
{
	game->mlx->cnt = mlx_init();
	if (!game->mlx->cnt)
		return (ft_err_msg("mlx_init failed", EXIT_FAILURE));
	game->mlx->wnd = mlx_new_window(game->mlx->cnt, WIDTH, HEIGHT, "Cub3d");
	if (!game->mlx->wnd)
		return (ft_err_msg("mlx_new_window failed", EXIT_FAILURE));
	game->mlx->img = mlx_new_image(game->mlx->cnt, WIDTH, HEIGHT);
	game->mlx->addr = mlx_get_data_addr(game->mlx->img,
			&game->mlx->bits_per_pixel, &game->mlx->line_length,
			&game->mlx->endian);
	get_texture_pointers(game);
	return (EXIT_SUCCESS);
}

/**
 * @brief Start the initial player position with values
 * depending on his direction.
 */
void	start_player_position(t_gm *game)
{
	game->ray->plyr_x = game->map->plyr_x + 0.5;
	game->ray->plyr_y = game->map->plyr_y + 0.5;
	if (game->map->plyr_dir == 'N')
	{
		set_plane_positions(game, 0.66, 0.0);
		set_direction_positions(game, 0.0, -1.0);
	}
	else if (game->map->plyr_dir == 'S')
	{
		set_plane_positions(game, -0.66, 0.0);
		set_direction_positions(game, 0.0, 1.0);
	}
	else if (game->map->plyr_dir == 'W')
	{
		set_plane_positions(game, 0.0, -0.66);
		set_direction_positions(game, -1.0, 0.0);
	}
	else if (game->map->plyr_dir == 'E')
	{
		set_plane_positions(game, 0.0, 0.66);
		set_direction_positions(game, 1.0, 0.0);
	}
}

/**
 * @note Auxiliar to start_player_position()
 * @brief Set plane_x\plane_y position
 */
void	set_plane_positions(t_gm *game, double plane_x, double plane_y)
{
	game->ray->plane_x = plane_x;
	game->ray->plane_y = plane_y;
}

/**
 * @note Auxiliar to start_player_position()
 * @brief Set dir_x\dir_y position
 */
void	set_direction_positions(t_gm *game, double dir_x, double dir_y)
{
	game->ray->dir_x = dir_x;
	game->ray->dir_y = dir_y;
}
