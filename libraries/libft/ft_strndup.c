/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:42:45 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:17:15 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Make the duplication of a word for a specific qt of characters
*/
char	*ft_strndup(char *str, int qt)
{
	char	*dup;
	int		i;

	if (!str)
		return (NULL);
	dup = malloc(sizeof(char) * qt + 1);
	if (!dup || !qt)
		return (NULL);
	i = 0;
	while (i < qt)
	{
		dup[i] = str[i];
		i ++;
	}
	dup[i] = '\0';
	return (dup);
}
