/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:36:04 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:11:12 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	main(int argc, char **argv)
{
	t_gm	game;


	ft_bzero(&game, sizeof(t_gm));
	if (!is_argument_valid(argc, argv))
		return (EXIT_FAILURE);
	
	if (run_mlx(&game))
		return (err_msg("Error Mlx Init", EXIT_FAILURE));

	start_game(&game);
	
	return (0);
}

/**
 * @brief Check if there are valid arguments || if the map file
 * is not an openble file or dont end with .cub;
 * @return argument valid = true. argument invalid = false.
*/
int is_argument_valid(int argc, char **argv)
{
	int	map_fd;
	int	invalid;
	int len;

	if (argc != 2)
		return (err_msg("Invalid quantity of arguments!", false));
	invalid = true;
	len = ft_strlen(argv[1]);
	if (len > 4 && !ft_strncmp(".cub", &argv[1][len - 4], 4))
		invalid = 0;
	map_fd = open(argv[1], O_RDONLY);
	if (invalid || map_fd < 0)
		return(err_msg("Invalid map file", false));
	close(map_fd);
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