/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matriz.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:41:10 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:16:57 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief just print an array of chars. 
 * Support function to help debbuging
*/
void	ft_printf_matriz(char **to_print)
{
	int	i;

	i = 0;
	if (!to_print)
		return ;
	while (to_print[i])
	{
		write(1, "Element ->", 10);
		write(1, to_print[i], ft_strlen(to_print[i]));
		write(1, "\n", 1);
		i ++;
	}
}
