/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:27:30 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/20 21:40:21 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_memchr function searches for the first occurrence
 * of the character c in the first n bytes of the memory block
 * pointed to by s.
 * @return A pointer to the matching byte or NULL if the character
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
/* 
//Function description
//The ft_memchr function searches for the first occurrence 
//of a character c in a memory block s of size n, returning a
//pointer to the character or NULL.

#include <stdio.h>

int main() {
    char str_test[] = "Amauri tesWting!";
    char search_char = 'W';
    size_t size = sizeof(str_test);

    char *result = ft_memchr(str_test, search_char, size);

    if (result != NULL) {
        printf("Char '%c' found index %ld in the string: %s\n", 
		search_char, result - str_test, str_test);
    } else {
        printf("Character '%c' not found in the string.\n", search_char);
    }

    return (0);
} */