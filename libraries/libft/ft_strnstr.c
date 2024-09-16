/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:37:01 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/20 21:58:22 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of the null-terminated string little in 
 * the string big, where not more than len characters are searched. 
 * Characters that appear after a `\0' character are not searched.
 * @return If little is an empty string, big is returned; 
 * if little occurs nowhere in big, NULL is returned; 
 * otherwise a pointer to the first character of the first 
 * occurrence of little is returned.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		while ((little[j] == big[i + j])
			&& (big[i + j] != '\0') && (i + j < len))
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/* 
#include <stdio.h>

int     main(void)
{
        char    main_str[] = "Vamos encontrar a agulha no palheiro ";
        char    find[] = "amos";
        char  *ret;

        //ret = strnstr(main_str, find, 5);
        printf("The substring is: %s\n", ret);
        printf("--------------------------\n");
        printf("%s", ft_strnstr(main_str, find, 5));
}
 */