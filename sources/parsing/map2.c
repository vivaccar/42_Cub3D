/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:49:57 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/18 12:00:38 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

bool	is_map_valid(t_gm *game)
{
	if (game->map->matriz[0] == NULL)
		return (ft_err_msg("Empty Map!", false));
	
	return (true);
}