/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:11:37 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 16:12:33 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/**
 * @brief Print a message of error in STDERR and return a given value;
*/
int err_msg(char *msg, int int_return)
{
	ft_putendl_fd("Error!", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	return (int_return);
}

void    free_game(t_gm *game)
{
	free(game->mlx);//This we will need to destroy after
	free(game->window);
	free(game->map);//This we will need to clean inside
}