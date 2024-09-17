/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:58:01 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/17 20:01:46 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

/**
 * @brief Check if a word is separated by space
 * example -> "This is Spaced" ; "ThisIsNotSpaced"
 * @return false for not spaced or !str, true for spaced.
 */
bool	is_spaced(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	while (str[i])
	{
		if (str[i + 1] && ft_isalpha(str[i + 1]) && str[i] == ' ')
			return (true);
		if (str[i + 1] && ft_isdigit(str[i + 1]) && str[i] == ' ')
		{
			i ++ ;
			continue ;
		}
		i ++;
	}
	return (false);
}

/**
 * @brief Verify if some of the elements of the map struct is null.
 */
bool	is_element_missing(t_gm *game)
{
	if (!game->map->f_color || !game->map->c_color || !game->map->ntex
		|| !game->map->stex || !game->map->etex || !game->map->wtex)
		return (true);
	return (false);
}

/**
 * @brief Check if the RGB colors are valid and extract them to the array
 * on the main struct
 */
bool	is_rgb_valid(t_gm *game)
{
	if (!is_color_format_valid(game->map->f_color)
		|| !is_color_format_valid(game->map->c_color))
	{
		return (ft_err_msg("Color element format not valid, try nbr, nbr, nbr",
				false));
	}
	extract_numbers(game->map->f_color, game->map->frgb, 0);
	extract_numbers(game->map->c_color, game->map->crgb, 0);
	if (game->map->frgb[0] > 255 || game->map->frgb[1] > 255
		|| game->map->frgb[2] > 255 || game->map->crgb[0] > 255
		|| game->map->crgb[1] > 255 || game->map->crgb[2] > 255)
		return (ft_err_msg("Color elements exceeds 255", false));
	return (true);
}

/**
 * @brief Extract numbers from a string and save them into an array
 */
void	extract_numbers(char *str, int arr[3], int i)
{
	int	num;
	int	in_number;
	int	index;

	num = 0;
	index = 0;
	in_number = 0;
	while (str[i] && index < 3)
	{
		if (ft_isdigit(str[i]))
		{
			num = num * 10 + (str[i] - '0');
			in_number = 1;
		}
		else if (in_number)
		{
			arr[index ++] = num;
			num = 0;
			in_number = 0;
		}
		i ++;
	}
	if (in_number && index < 3)
		arr[index] = num;
}

/**
 * @brief Check to see if the formar of the color string is nbr, nbr, nbr
 */
bool	is_color_format_valid(char *str)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] != ',' && str[i] != ' ')
				return (false);
			if (str[i] == ' ' && i > 0 && ft_isdigit(str[i - 1])
				&& str[i + 1] && ft_isdigit(str[i + 1]))
				return (false);
		}
		if (str[i] == ',')
			comma ++;
		i ++;
	}
	if (comma != 2)
		return (false);
	return (true);
}
