/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:11:37 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/10 20:30:10 by aconceic         ###   ########.fr       */
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