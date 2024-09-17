/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:39:18 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/17 17:37:07 by vivaccar         ###   ########.fr       */
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

#define WIDTH 1920
#define HEIGHT 1040

//Mlx Lib Struc
typedef struct s_mlx
{
	void	*cnt;
	void	*wnd;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

//Window Struc
typedef struct s_window
{
	int	h;
	int	w;
}	t_window;

typedef struct s_map
{
	int		fd;
	char	**matriz;
	int		f_color;
	int		c_color;
	char	*ntex;
	char	*stex;
	char	*etex;
	char	*wtex;
	char	plyr_dir;
    double 	plyr_x;
    double 	plyr_y;
    double 	plane_x;
    double 	plane_y;
	double	dirX;
	double	dirY;
	// ceiling clr
}	t_map;

//Main Struc gm = GaMe.
typedef struct s_gm
{
	t_mlx		*mlx;
	t_window	*window;
	t_map		*map;
}	t_gm;

int		main(int argc, char **argv);
bool	is_argument_valid(t_gm *game, int argc, char **argv);

//free.c
int		err_msg(char *msg, int int_return);
void    free_game(t_gm *game);

//init.c
int		run_mlx(t_gm *game);
int		init_game_struct(t_gm *game);
void	init_map_struct(t_gm *game);

//map_parsing.c
int		parse_map(t_gm *game, int argc, char **argv);

//start_game.c
void 	start_game(t_gm *game);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	draw_floor_ceiling(t_gm *game, t_mlx *mlx);
void	raycaster(t_gm *game);
