/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 22:22:54 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:17:25 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_usleep(size_t time)
{
	size_t	start;

	time = time / 1000;
	start = ft_get_time();
	while (ft_get_time() - start < time)
		usleep(500);
}
