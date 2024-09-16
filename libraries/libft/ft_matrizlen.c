/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrizlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:11:55 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:16:26 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_matrizlen(char **to_count)
{
	int	i;

	i = 0;
	if (!to_count)
		return (0);
	while (to_count[i])
		i ++;
	return (i);
}
