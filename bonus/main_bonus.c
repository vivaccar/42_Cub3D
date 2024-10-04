/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:36:04 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/04 14:10:15 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_bonus.h"

/**
 * @brief Run Cub
 * @attention mlx_mouse_hide() -> function cause leaks
 */
void	run_cub(t_gm *game)
{
	start_player_position(game);
	mlx_mouse_hide(game->mlx->cnt, game->mlx->wnd);
	mlx_mouse_hook(game->mlx->wnd, mouse_fire, game);
	mlx_loop_hook(game->mlx->cnt, &raycaster, game);
	mlx_hook(game->mlx->wnd, 2, 1L << 0, key_press_handler, game);
	mlx_hook(game->mlx->wnd, 6, 1L << 6, mouse_handler, game);
	mlx_hook(game->mlx->wnd, 17, 0, close_cub, game);
	mlx_loop(game->mlx->cnt);
}

/**
 * Digital Differential Analysis Algorthm - Search for it
 */
int	main(int argc, char **argv)
{
	t_gm	game;

	printf("This is the bonus main");
	if (init_game_struct(&game))
		return (EXIT_FAILURE);
	if (!is_argument_valid(&game, argc, argv))
		return (free_game(&game, 1), EXIT_FAILURE);
	if (parse_file(&game, argc, argv))
		return (free_game(&game, 1), EXIT_FAILURE);
	print_map_values(&game);
	if (run_mlx(&game))
		return (ft_err_msg("Error Mlx Init", EXIT_FAILURE));
	run_cub(&game);
	return (0);
}

/**
 * @brief Check if there are valid arguments || if the map file
 * is not an openble file or dont end with .cub;
 * @return argument valid = true. argument invalid = false.
*/
bool	is_argument_valid(t_gm *game, int argc, char **argv)
{
	if (argc != 2)
		return (ft_err_msg("Invalid quantity of arguments!", false));
	if (!is_openble_file(argv[1], ".cub", 4))
		return (false);
	game->map->fd = open(argv[1], O_RDONLY);
	return (true);
}
