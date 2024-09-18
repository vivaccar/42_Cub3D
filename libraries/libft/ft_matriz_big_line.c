/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matriz_big_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:41:47 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/18 12:42:06 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Gets the size of the biggest line on a matriz
 */
int	ft_matriz_big_line(char **matriz)
{
	int	size;
	int	i;

	if (!matriz)
		return (0);
	size = (int)ft_strlen(matriz[0]);
	i = 0;
	while (matriz[i])
	{
		if ((int)ft_strlen(matriz[i]) > size)
			size = ft_strlen(matriz[i]);
		i ++;
	}
	return (size);
}
