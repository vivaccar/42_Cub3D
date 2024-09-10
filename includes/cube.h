/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:39:18 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/10 21:30:38 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h> //malloc() free() exit()
# include <unistd.h> //open() close() read() write()
# include <stdio.h> //perror()
# include <string.h> //strerror()
# include <sys/time.h> //gettimeofday()
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>

# include "../libraries/libft/libft.h"
# include "../libraries/minilibx-linux/mlx.h"
# include "../libraries/minilibx-linux/mlx_int.h"

//Mlx Lib Struc
typedef struct s_mlx
{
	void	*cnt;
	void	*wnd;
}	t_mlx;

//Window Struc
typedef struct s_window
{
	int	h;
	int	w;
}	t_window;

//Main Struc gm = GaMe.
typedef struct s_gm
{
	t_mlx		*mlx;
	t_window	*window;
}	t_gm;

int	main(int argc, char **argv);
int is_argument_valid(int argc, char **argv);

//free.c
int err_msg(char *msg, int int_return);

//init.c
int	run_mlx(t_gm *game);

//map_parsing.c
