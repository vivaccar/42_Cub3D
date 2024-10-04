/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:49:58 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/04 16:23:06 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_bonus.h"

/**
 * @brief Start the main struct(game) with initial values
 * and allocate memory for the substructs;
 * @attention Error handling trough init_game_error_handling()
 * to keep track in case of errors during allocations;
 */
int	init_game_struct(t_gm *game)
{
	ft_bzero(game, sizeof(t_gm));
	game->map = malloc(sizeof(t_map));
	ft_bzero(game->map, sizeof(t_map));
	game->map->cc_rgb[0] = -1;
	game->map->cc_rgb[1] = -1;
	game->map->cc_rgb[2] = -1;
	game->map->fc_rgb[0] = -1;
	game->map->fc_rgb[1] = -1;
	game->map->fc_rgb[2] = -1;
	game->ray = malloc(sizeof(t_ray));
	ft_bzero(game->ray, sizeof(t_ray));
	game->ray->mov_speed = 0.07;
	game->mlx = malloc(sizeof(t_mlx));
	game->mm = malloc(sizeof(t_minmap));
	ft_bzero(game->mm, sizeof(t_minmap));
	game->textr = malloc(sizeof(t_texture));
	ft_bzero(game->textr, sizeof(t_texture));
	init_gun_struct(game);
	if (init_game_error_handling(game))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * @note Called on run_mlx()
 * @brief Get the texture and save them on pointers, 
 * getting also info about the texture (width and height)
 * use mlx_xpm_file_to_image() to get the info/image.
 * @attention index 0 from 3 to wall textures. Index 4 and 5 to gun texture.
 * index 6 to aim texture.
 */
void	get_texture_pointers(t_gm *game)
{
	t_texture	*t;
	t_mlx		*cnt;

	t = game->textr;
	cnt = game->mlx->cnt;
	t->texture[0] = mlx_xpm_file_to_image(cnt, game->map->ntex,
			&game->textr->txt_width[0], &game->textr->txt_height[0]);
	t->texture[1] = mlx_xpm_file_to_image(cnt, game->map->stex,
			&game->textr->txt_width[1], &game->textr->txt_height[1]);
	t->texture[2] = mlx_xpm_file_to_image(cnt, game->map->wtex,
			&game->textr->txt_width[2], &game->textr->txt_height[2]);
	t->texture[3] = mlx_xpm_file_to_image(cnt, game->map->etex,
			&game->textr->txt_width[3], &game->textr->txt_height[3]);
	t->texture[4] = mlx_xpm_file_to_image(cnt, "textures/gun1.xpm",
			&game->textr->txt_width[4], &game->textr->txt_height[4]);
	t->texture[5] = mlx_xpm_file_to_image(cnt, "textures/gun2.xpm",
			&game->textr->txt_width[5], &game->textr->txt_height[5]);
	t->texture[6] = mlx_xpm_file_to_image(cnt, "textures/aim.xpm",
			&game->textr->txt_width[6], &game->textr->txt_height[6]);
	printf("%i\n%i\n", game->textr->txt_height[4], game->textr->txt_width[4]);
	if (t->texture[0] == NULL || t->texture[1] == NULL
		|| t->texture[2] == NULL || t->texture[3] == NULL
		|| t->texture[4] == NULL || t->texture[5] == NULL
		|| t->texture[6] == NULL)
		ft_err_msg("Failed texture image init", EXIT_FAILURE);
}

/**
 * @note Called on init_game_struct()
 * @brief Treat possible allocation errors and free the ptrs if necessary;
 * Returns EXIT_SUCCESS (0) if no errors,
 * EXIT_FAILURE(1) if error(doing necessary frees);
 */
int	init_game_error_handling(t_gm *game)
{
	if (!game || !game->gun || !game->map || !game->mlx
		|| !game->mm || !game->ray || !game->textr)
	{
		if (game->gun)
			free(game->gun);
		if (game->map)
			free(game->map);
		if (game->mlx)
			free(game->mlx);
		if (game->mm)
			free(game->mm);
		if (game->ray)
			free(game->ray);
		if (game->textr)
			free(game->textr);
		if (game)
			free(game);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
