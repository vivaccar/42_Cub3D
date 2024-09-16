/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:52:31 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/20 21:53:15 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Appends the src string to the dst string, ensuring the total length 
 * does not exceed size. It returns the length of the resulting string.
 * @return The length of the resulting string.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = 0;
	res = 0;
	while (dst[i])
		i++;
	while (src[res])
		res ++;
	if (size <= i)
		res += size;
	else
		res += i;
	while (src[j] && (i + 1) < size)
	{
		dst[i] = src[j];
		i ++;
		j ++;
	}
	dst[i] = '\0';
	return (res);
}
/*
#include <stdio.h>

int main() {
    char destination[50] = "This is just, ";
    const char *source = "a concatenation!";
    size_t destination_size = sizeof(destination);

    size_t result = ft_strlcat(destination, source, destination_size);

    printf("Concatenated string: %s\n", destination);
    printf("Resulting length: %zu\n", result);

    return 0;
}
 */