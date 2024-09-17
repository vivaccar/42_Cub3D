/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:06:16 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/17 16:17:09 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Search for the incidente of to_find inside the str.
 * Ignore initial tabs and spaces.
 * If !str or !to_find, return NULL. If !to_find, return NULL.
 * If find the first incidente, return a pointer to it.
 */
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(to_find);
	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	while (str[i])
	{
		if (!ft_strncmp(&str[i], to_find, len))
			return (&str[i]);
		i ++;
	}
	return (NULL);
}
