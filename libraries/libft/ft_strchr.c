/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:15:59 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:14:08 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief ft_strchr searches for the first occurrence of 
 * character c in the string s,
 * returning a pointer to the character or NULL if not found.
 * @return char* A pointer to the character or NULL if not found.
*/
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char )c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char )c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/* 

#include <stdio.h>

int main(void)
{
	char *res;
	char *name;
	name = "amauri";
	res = ft_strchr(name, 'm');

	printf("%s", res);
} */