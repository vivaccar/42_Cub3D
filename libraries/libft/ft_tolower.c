/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:37:54 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:15:20 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts an uppercase character to its corresponding 
 * lowercase character.
 * @return The lowercase character. If the input is not uppercase, 
 * it remains unchanged.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/* 
#include <stdio.h>

int main() {
    int uppercase = 'Z';
    int lowercase = ft_tolower(uppercase);

    printf("Uppercase: %c\n", uppercase);
    printf("Lowercase: %c\n", lowercase);

    return 0;
}
*/