/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:36:04 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:47:44 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	main(int argc, char **argv)
{
	t_gm	game;

	if (init_game_struct(&game, argc, argv))
		return (EXIT_FAILURE);
	if (!is_argument_valid(&game))
		return (free_game(&game), EXIT_FAILURE);
	if (parse_map(&game, argc, argv))
		return (free_game(&game), EXIT_FAILURE);
	if (run_mlx(&game))
			return (err_msg("Error Mlx Init", EXIT_FAILURE));
	
	start_game(&game);
	free_game(&game);
	return (0);
}

/**
 * @brief Check if there are valid arguments || if the map file
 * is not an openble file or dont end with .cub;
 * @return argument valid = true. argument invalid = false.
*/
bool is_argument_valid(t_gm *game)
{
	int	invalid;
	int len;

	if (game->argc_cpy != 2)
		return (err_msg("Invalid quantity of arguments!", false));
	invalid = 1;
	len = ft_strlen(game->argv_cpy[1]);
	if (len > 4 && !ft_strncmp(".cub", &game->argv_cpy[1][len - 4], 4))
		invalid = 0;
	game->map->fd = open(game->argv_cpy[1], O_RDONLY); // dont forget to close this
	if (invalid || game->map->fd < 0)
		return(err_msg("Invalid map file", false));
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