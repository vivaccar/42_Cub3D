/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:20:16 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/20 15:41:08 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void print_map_values(t_gm *game)
{
	printf("\n" BLUE "========= MAP INFORMATION =========" RESET "\n");

	// Print map matriz
	printf("\n" CYAN "-- MATRIZ --" RESET "\n");
	ft_printf_matriz(game->map->matriz);

	// Print textures information
	printf("\n" YELLOW "-- TEXTURES --" RESET "\n");
	printf("Floor Color (Str):   " GREEN "%s" RESET "\n", game->map->fc_str);
	printf("Ceiling Color (Str): " GREEN "%s" RESET "\n", game->map->cc_str);
	printf("North Texture Path:  " GREEN "%s" RESET "\n", game->map->ntex);
	printf("South Texture Path:  " GREEN "%s" RESET "\n", game->map->stex);
	printf("East Texture Path:   " GREEN "%s" RESET "\n", game->map->etex);
	printf("West Texture Path:   " GREEN "%s" RESET "\n", game->map->wtex);

	// Print player information
	printf("\n" MAGENTA "-- PLAYER INFO --" RESET "\n");
	printf("Player Direction:    " RED "%c" RESET "\n", game->map->plyr_dir);
	printf("Player X Position:   " RED "%.2f" RESET "\n", game->map->plyr_x);
	printf("Player Y Position:   " RED "%.2f" RESET "\n", game->map->plyr_y);

	// Print plane information
	printf("\n" BLUE "-- PLANE INFO --" RESET "\n");
	printf("Plane X:             " CYAN "%.2f" RESET "\n", game->map->plane_x);
	printf("Plane Y:             " CYAN "%.2f" RESET "\n", game->map->plane_y);

	// Print hex colors
	printf("\n" YELLOW "-- HEX COLORS --" RESET "\n");
	printf("Floor HEX:           " WHITE "%#X" RESET "\n", game->map->fc_hex);
	printf("Ceiling HEX:         " WHITE "%#X" RESET "\n", game->map->cc_hex);

	// Print direction vectors
	printf("\n" MAGENTA "-- DIRECTIONS --" RESET "\n");
	printf("Direction X:         " RED "%.2f" RESET "\n", game->map->dirX);
	printf("Direction Y:         " RED "%.2f" RESET "\n", game->map->dirY);

	printf("\n" BLUE "===================================" RESET "\n");
}

/**
 * @brief
*/
bool	jump_spaces(char ch, int *j, int backwards)
{
	if (ch == ' ' && !backwards)
	{
		(*j)++;
		return (true);
	}
	if (ch == ' ' && backwards)
	{
		(*j)--;
		return (true);
	}
	return (false);
}
