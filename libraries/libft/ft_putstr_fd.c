/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:23:01 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:13:58 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs the string s to the file descriptor fd.
 */
void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i ++;
	}
}

//function description
//ft_putstr_fd writes a string s to a specified file descriptor 
//fd. It iterates through the characters in the string and outputs them.