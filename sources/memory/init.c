/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:49:58 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/04 16:27:42 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	init_textr_struct(t_gm *game)
{
	game->textr->wall_texture[0] = NULL;
	game->textr->wall_texture[1] = NULL;
	game->textr->wall_texture[2] = NULL;
	game->textr->wall_texture[3] = NULL;
	game->textr->txt_x = 0;
	game->textr->txt_y = 0;
	game->textr->text_pos = 0;
	game->textr->r_line_len = 0;
	game->textr->r_first_point = 0;
	game->textr->r_last_point = 0;
	game->textr->wall_hit_pos = 0;
	game->textr->step = 0;
	game->textr->bits_per_pixel = 0;
	game->textr->endian = 0;
	game->textr->line_len = 0;
}

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
	game->ray = malloc(sizeof(t_ray));
	if (!game->ray)
		return (ft_err_msg("Error allocating ray struct", EXIT_FAILURE));
	init_ray_struct(game);
	game->mlx = malloc(sizeof(t_mlx));
	if (!game->mlx)
	{
		free(game->map);
		return (ft_err_msg("Error allocating mlx", EXIT_FAILURE));
	}
	game->textr = malloc(sizeof(t_texture));
	if (!game->textr)
		return (ft_err_msg("Error allocating texture struct", EXIT_FAILURE));
	init_textr_struct(game);
	return (EXIT_SUCCESS);
}

void	init_ray_struct(t_gm *game)
{
	game->ray->dir_x = 0.0;
	game->ray->dir_y = 0.0;
	game->ray->plane_x = 0.0;
	game->ray->plane_y = 0.0;
	game->ray->cam_x = 0.0;
	game->ray->ray_dir_x = 0.0;
	game->ray->ray_dir_y = 0.0;
	game->ray->map_x = 0;
	game->ray->map_y = 0;
	game->ray->side_dstc_x = 0.0;
	game->ray->side_dstc_x = 0.0;
	game->ray->delta_dstc_x = 0.0;
	game->ray->delta_dstc_y = 0.0;
	game->ray->wall_ppclr_dstc = 0.0;
	game->ray->step_x = 0;
	game->ray->step_y = 0;
	game->ray->side_hit = 0;
	game->ray->plyr_x = 0;
	game->ray->plyr_y = 0;
	game->ray->mov_speed = 0.07;
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
	game->map->fc_rgb[0] = -1;
	game->map->fc_rgb[1] = -1;
	game->map->fc_rgb[2] = -1;
	game->map->cc_rgb[0] = -1;
	game->map->cc_rgb[1] = -1;
	game->map->cc_rgb[2] = -1;
	game->map->fc_hex = 0;
	game->map->cc_hex = 0;
	game->map->h = 0;
	game->map->w = 0;
}

void	get_texture_pointers(t_gm *game)
{
	t_texture	*t;
	t_mlx		*cnt;

	t = game->textr;
	cnt = game->mlx->cnt;
	t->wall_texture[0] = mlx_xpm_file_to_image(cnt, game->map->ntex,
			&game->textr->txt_width[0], &game->textr->txt_height[0]);
	t->wall_texture[1] = mlx_xpm_file_to_image(cnt, game->map->stex,
			&game->textr->txt_width[1], &game->textr->txt_height[1]);
	t->wall_texture[2] = mlx_xpm_file_to_image(cnt, game->map->wtex,
			&game->textr->txt_width[2], &game->textr->txt_height[2]);
	t->wall_texture[3] = mlx_xpm_file_to_image(cnt, game->map->etex,
			&game->textr->txt_width[3], &game->textr->txt_height[3]);
	if (t->wall_texture[0] == NULL || t->wall_texture[0] == NULL
		|| t->wall_texture[0] == NULL || t->wall_texture[0] == NULL)
		ft_err_msg("Failed texture image init", EXIT_FAILURE);
}
