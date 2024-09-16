/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:58:13 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/31 19:15:36 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Verify if an INT is printable
 * @param c int to be checked.
 * @return 16384 for true, 0 for false.
*/
int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (16384);
	else
		return (0);
}
