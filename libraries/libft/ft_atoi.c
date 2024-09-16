/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:03:48 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/31 19:02:03 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convert ascii to integer
 * @param nptr ascii to be converted to ingeter
 * @return The integer equivalent to the ascii paramether
*/
int	ft_atoi(const char *nptr)
{
	int		signal;
	int		number;

	signal = 1;
	number = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal = -1;
		nptr ++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		number *= 10;
		number += *nptr - 48;
		nptr ++;
	}
	number *= signal;
	return (number);
}
