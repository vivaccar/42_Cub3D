/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:20:16 by aconceic          #+#    #+#             */
/*   Updated: 2024/10/07 13:05:01 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube_bonus.h"

/**
 * @brief Function constructed mainly for debug.
 * Print some values on STDIN_FILENO.
 */
void	print_map_values(t_gm *game)
{
	printf("\n" BLUE "========= MAP INFORMATION =========" RESET "\n");
	printf("\n" CYAN "-- MATRIZ --" RESET "\n");
	ft_printf_matriz(game->map->matriz);
	printf("\n" YELLOW "======= TEXTURES =======" RESET "\n");
	printf("Floor Color (Str):   " GREEN "%s" RESET "\n", game->map->fc_str);
	printf("Ceiling Color (Str): " GREEN "%s" RESET "\n", game->map->cc_str);
	printf("North Texture Path:  " GREEN "%s" RESET "\n", game->map->ntex);
	printf("South Texture Path:  " GREEN "%s" RESET "\n", game->map->stex);
	printf("East Texture Path:   " GREEN "%s" RESET "\n", game->map->etex);
	printf("West Texture Path:   " GREEN "%s" RESET "\n", game->map->wtex);
	printf("\n" MAGENTA "======= PLAYER INFO =======" RESET "\n");
	printf("Player Direction:    " RED "%c" RESET "\n", game->map->plyr_dir);
	printf("Player X Position:   " RED "%.2f" RESET "\n", game->map->plyr_x);
	printf("Player Y Position:   " RED "%.2f" RESET "\n", game->map->plyr_y);
	printf("\n" BLUE "======= PLANE INFO =======" RESET "\n");
	printf("Plane X:             " CYAN "%.2f" RESET "\n", game->ray->plane_x);
	printf("Plane Y:             " CYAN "%.2f" RESET "\n", game->ray->plane_y);
	printf("\n" YELLOW "======= HEX COLORS =======" RESET "\n");
	printf("Floor HEX:           " WHITE "%#X" RESET "\n", game->map->fc_hex);
	printf("Ceiling HEX:         " WHITE "%#X" RESET "\n", game->map->cc_hex);
	printf("\n" MAGENTA "======= DIRECTIONS =======" RESET "\n");
	printf("Direction X:         " RED "%.2f" RESET "\n", game->ray->dir_x);
	printf("Direction Y:         " RED "%.2f" RESET "\n", game->ray->dir_y);
	printf("\n" BLUE "===================================" RESET "\n");
}

/**
 * @brief Move a characther if is a space
 * If have int backwards, decrement j value.
 * If dont, acrecent.
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

/**
 * @brief Check some file has a specific extention and if its an openble file
 * if NULL is passed on extention, just check if its an openble file
*/
bool	is_openble_file(char *path, char *extention, int ext_len)
{
	int		len;
	int		fd;
	char	*err_msg;

	len = 0;
	fd = -1;
	len = ft_strlen(path);
	err_msg = ft_strjoin(path, " - Not a valid file!");
	if (extention)
	{
		if (len > ext_len
			&& ft_strncmp(extention, &path[len - ext_len], ext_len))
		{
			ft_err_msg(err_msg, false);
			return (free(err_msg), false);
		}
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_err_msg(err_msg, false);
		return (free(err_msg), false);
	}
	return (free(err_msg), true);
}
