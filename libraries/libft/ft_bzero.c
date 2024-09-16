/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:49:03 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/31 19:06:20 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Takes a specific number of bytes in memory an give them value of 0.
 * @param s pointer
 * @param n size
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;

	a = (unsigned char *)s;
	while (n--)
		*a ++ = 0;
}

//Function description
//Takes a specific number of bytes in memory and giver them 
//the value of 0
