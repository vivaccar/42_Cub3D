/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:39:18 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 17:57:22 by aconceic         ###   ########.fr       */
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

typedef struct s_map
{
	int		fd;
	char	**matriz;
	char	*f_color;
	char	*c_color;
	char	*ntex;
	char	*stex;
	char	*etex;
	char	*wtex;
	char	plyr_dir;
    float 	plyr_x;
    float 	plyr_y;
    float 	plane_x;
    float 	plane_y;
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
void	free_map(t_map *map);

//init.c
int		run_mlx(t_gm *game);
int		init_game_struct(t_gm *game);
void	init_map_struct(t_gm *game);

//map_parsing.c
int		parse_map(t_gm *game, int argc, char **argv);
char	**get_mapfile_info(t_gm *game, char *file_path);
char	*get_element_info(char *str);
int		fd_lines_counter(char *file_path);

//start_game.c
void start_game(t_gm *game);
