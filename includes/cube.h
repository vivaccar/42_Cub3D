/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:39:18 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/09 22:28:44 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h> //malloc() free() exit()
# include <unistd.h> //open() close() read() write()
# include <stdio.h> //perror()
# include <string.h> //strerror()
# include <sys/time.h> //gettimeofday()
# include <math.h>
# include <fcntl.h>


typedef struct s_mlx
{
	void	*cnt;
	void	*wnd;
}	t_mlx;

typedef struct s_dt
{
	t_mlx	*lb_mlx;
}	t_dt;

int	main(int argc, char **argv);
