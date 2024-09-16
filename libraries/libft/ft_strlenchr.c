/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:49:22 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:17:10 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Get the len of a *str until find a specific char.
*/
int	ft_strlenchr(char *str, char ch)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			break ;
		i ++;
	}
	return (i);
}
