/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:53:35 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/31 19:14:31 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Verify if an INT is ascii.
 * @param c int to be checked.
 * @return 1 for true, 0 for false.
*/
int	ft_isascii(int c)
{
	if (!(c >= 0 && c <= 127))
		return (0);
	else
		return (1);
}
