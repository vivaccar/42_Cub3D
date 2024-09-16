/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:36:00 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/20 22:00:20 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief searches for the last occurrence of character c in string s.
 * @return a pointer to the last occurrence or NULL if not found.
*/
char	*ft_strrchr(const char *s, int c)
{
	int		length;
	char	*last_occurence;

	last_occurence = NULL;
	length = 0;
	if ((char )c == 0)
	{
		while (s[length] != '\0')
			length ++;
		return ((char *)&s[length]);
	}
	while (s[length] != '\0')
	{
		if (s[length] == (char )c)
			last_occurence = ((char *)&s[length]);
		length ++;
	}
	return (last_occurence);
}

/* 
#include <stdio.h>.
int	main(void)
{
	printf("Mine %s\n", ft_strrchr("amauri", 'a'));
	printf("They %s\n", strrchr("amauri", 'a'));
}
 */