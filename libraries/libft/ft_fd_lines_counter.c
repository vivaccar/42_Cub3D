/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_lines_counter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:10:02 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/17 16:17:00 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Used on get_mapfile_info(), to alloc memory to the file
 * @return The number of the lines of a specific fd
 */
int	ft_fd_lines_counter(char *file_path)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (ft_err_msg("Invalid FD", -1));
	i = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i ++;
	}
	free(line);
	close(fd);
	return (i);
}
