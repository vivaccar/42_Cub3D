/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:12:42 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/17 16:16:46 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Print a message of error in STDERR and return a given value;
*/
int	ft_err_msg(char *msg, int int_return)
{
	ft_putendl_fd("Error!", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	return (int_return);
}
