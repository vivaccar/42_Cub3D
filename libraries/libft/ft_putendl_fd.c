/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:42:05 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/20 21:46:03 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs the string s to the file descriptor fd followed by a newline.
 */
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write (fd, s++, 1);
	write (fd, "\n", 1);
}
//Function description
//ft_putendl_fd writes a string s to a specified file descriptor fd 
//followed by a newline character. It's used for outputting a line of text.