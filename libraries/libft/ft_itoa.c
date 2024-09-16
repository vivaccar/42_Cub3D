/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:00:52 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/31 19:22:06 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Check how many algarisms exists in a number
 * @param n number to be checked.
 * @return The number of algarisms in a number.
*/
static	int	n_size(int n)
{
	int				i;
	unsigned int	nb;

	i = 1;
	nb = n;
	if (n < 0)
	{
		nb = -n;
		i ++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		i ++;
	}
	return (i);
}

/**
 * @brief Convert an INT to a string,
 * allocating memory for the result and handling negative numbers.
 * @param n INT to be converted.
 * @return A pointer to the ASCII equivalent of the param n.
*/
char	*ft_itoa(int n)
{
	int				qt_n;
	unsigned int	number;
	char			*res;

	qt_n = n_size(n);
	number = n;
	res = ft_calloc(sizeof(char), qt_n + 1);
	if (!res)
		return (NULL);
	res[qt_n] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		number = -n;
	}
	while (qt_n > 0 && res[--qt_n] != '-')
	{
		res[qt_n] = (number % 10) + '0';
		number = number / 10;
	}
	return (res);
}
