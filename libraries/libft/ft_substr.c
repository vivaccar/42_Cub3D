/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:28:22 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/20 22:06:32 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the string ’s’.
 * @return The substring. NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result_str;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len + start > ft_strlen(s))
		len = ft_strlen(&s[start]);
	result_str = malloc(len + 1);
	if (result_str == NULL)
		return (NULL);
	while (i < len)
	{
		result_str[i] = s[start + i];
		i ++;
	}
	result_str[i] = '\0';
	return (result_str);
}

/*
#include <stdio.h>

int main() {
    const char *source = "This is a test string";
    unsigned int start = 10;
    size_t length = 4;

    char *result = ft_substr(source, start, length);

    if (result != NULL) {
        printf("Original: %s\n", source);
        printf("Substring: %s\n", result);
        free(result); // Don't forget to free the allocated memory.
    } else {
        printf("Substr extraction failed.\n");
    }
    return (0);
}
 */