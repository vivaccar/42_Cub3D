/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:50:16 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:15:09 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a copy of ’s1’ 
 * with the characters 
 * specified in ’set’ removed from the beginning and the end of 
 * the string.
 * @return The trimmed string. NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		res_size;
	int		leng;

	leng = ft_strlen(s1);
	start = 0;
	end = leng - 1;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start ++;
	if (start >= leng)
		return (ft_strdup(""));
	else
	{
		while (end >= 0 && ft_strchr(set, s1[end]))
			end --;
	}
	res_size = end - start + 1;
	return (ft_substr(s1, start, res_size));
}
/* 
#include <stdio.h>

int	main(void)
{
	char	*name = "!!--!!amauri!@@--!";
	char	*set = "!";
	char	*result = ft_strtrim(name, set);
	
	printf("%s", result);
	return (0);
} */