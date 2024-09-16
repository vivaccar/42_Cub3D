/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:00:58 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/20 21:56:00 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares the first n bytes of strings s1 and s2.
 * @return An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]))
		i ++;
	if (n == i)
		return (0);
	else
		return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
}
/* 
#include <stdio.h>

int main() {
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, Universe!";
    size_t n = 6; // Compare the first 6 characters

    int result = ft_strncmp(str1, str2, n);

    if (result == 0) {
        printf("The strings are equal up to %zu characters.\n", n);
    } else {
        printf("The strings differ at character %zu.\n", n);
    }

    return (0);
}
 */