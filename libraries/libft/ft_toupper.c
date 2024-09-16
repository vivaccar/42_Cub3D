/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:59:24 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:15:34 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts a lowercase character to its corresponding 
 * uppercase character.
 * @return The uppercase character. If the input is not a lowercase 
 * character, it remains unchanged.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*
#include <stdio.h>

int main() {
    int lowercase = 'a';
    int uppercase = ft_toupper(lowercase);

    printf("Lowercase: %c\n", lowercase);
    printf("Uppercase: %c\n", uppercase);

    return (0);
}
*/