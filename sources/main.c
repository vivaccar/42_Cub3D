/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:36:04 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/22 13:46:35 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	esc_close(t_gm *game)
{
	(void) game;
	//free(game);
	exit(0);
}

void	move_up(t_gm *game)
{
	game->ray->plyr_y += game->ray->dirY * 0.05;
}

void	move_down(t_gm *game)
{
	game->ray->plyr_y -= game->ray->dirY * 0.05;
}

void	move_left(t_gm *game)
{
	game->ray->plyr_x -= 0.05;
}

void	move_right(t_gm *game)
{
	game->ray->plyr_x += 0.05;
}

int	key_press_handler(int keycode, t_gm *game)
{
	(void)keycode;
	
	if (keycode == KEY_ESC)
		esc_close(game);
	else if (keycode == KEY_W)
		move_up(game);
	else if (keycode == KEY_S)
		move_down(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_D)
		move_right(game);
	printf("%i", game->ray->map_x);
	//game->ray->map_y += game->ray->dirY;
	printf("%i", game->ray->map_y);
	return (0);
}

void	run_cub(t_gm *game)
{
	start_positions(game);
	mlx_loop_hook(game->mlx->cnt, &raycaster, game);
	mlx_hook(game->mlx->wnd, 2, 1L << 0, key_press_handler, game);
	mlx_loop(game->mlx->cnt);
}

int	main(int argc, char **argv)
{
	t_gm	game;

	if (init_game_struct(&game))
		return (EXIT_FAILURE);
	if (!is_argument_valid(&game, argc, argv))
		return (free_game(&game), EXIT_FAILURE);
	if (parse_file(&game, argc, argv))
		return (free_game(&game), EXIT_FAILURE);
	print_map_values(&game);
	if (run_mlx(&game))
		return (ft_err_msg("Error Mlx Init", EXIT_FAILURE));
	run_cub(&game);
	free_game(&game);
	return (0);
}

/**
 * @brief Check if there are valid arguments || if the map file
 * is not an openble file or dont end with .cub;
 * @return argument valid = true. argument invalid = false.
*/
bool	is_argument_valid(t_gm *game, int argc, char **argv)
{
	int	invalid;
	int	len;

	if (argc != 2)
		return (ft_err_msg("Invalid quantity of arguments!", false));
	invalid = 1;
	len = ft_strlen(argv[1]);
	if (len > 4 && !ft_strncmp(".cub", &argv[1][len - 4], 4))
		invalid = 0;
	game->map->fd = open(argv[1], O_RDONLY); // dont forget to close this
	if (invalid || game->map->fd < 0)
		return (ft_err_msg("Invalid map file", false));
	return (true);
}
//path
//create window
//parse the map
	// extracting relevant information such as the map dimensions, 
	//player position, and the map layout itself. 
	//The map is validated to ensure its correctness, 
	//and memory is allocated to store the map information. 
	//This part sets the foundation for the rest of the project by 
	//providing the necessary data to render the game world.