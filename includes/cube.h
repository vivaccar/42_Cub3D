/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:39:18 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/18 16:37:41 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //malloc() free() exit()
#include <unistd.h> //open() close() read() write()
#include <stdio.h> //perror()
#include <string.h> //strerror()
#include <sys/time.h> //gettimeofday()
#include <math.h>
#include <fcntl.h>
#include <stdbool.h>
#include <limits.h>

#include "../libraries/libft/libft.h"
#include "../libraries/minilibx-linux/mlx.h"
#include "../libraries/minilibx-linux/mlx_int.h"

#define WIDTH 1920
#define HEIGHT 1040

// Define color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"


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
	char	*fc_str;
	char	*cc_str;
	char	*ntex;
	char	*stex;
	char	*etex;
	char	*wtex;
	char	plyr_dir;
	double 	plyr_x;
	double 	plyr_y;
	double 	plane_x;
	double 	plane_y;
	int		fc_rgb[3];
	int		cc_rgb[3];
	int		fc_hex;
	int		cc_hex;
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
void	free_game(t_gm *game);
void	free_map(t_map *map);

//init.c
int		run_mlx(t_gm *game);
int		init_game_struct(t_gm *game);
void	init_map_struct(t_gm *game);

//parsing/scene.c
int		parse_file(t_gm *game, int argc, char **argv);
char	**get_mapfile_info(t_gm *game, char *file_path);
void	replace_tabs_to_space(char **cub);

//parsing/elements.c
void	get_texture_and_color(t_gm *game, char	**matriz);
char	*get_element_info(char *str);
bool	is_texture_and_color_valid(t_gm *game, char **matriz);
bool	is_spaced(char *str);

//parsing/elements2.c
bool	is_element_missing(t_gm *game);
bool	is_rgb_valid(t_gm *game);
void	extract_numbers(char *str, int arr[3], int i);
bool	is_color_format_valid(char *str);
void	convert_color_system(t_gm *game);

//parsing/map.c
void	extract_map(t_gm *game, char **scene);
int		find_starting_point(char **scene);
bool	is_empty_line(char *line);
void	make_map_rectangle(t_gm *game);
char	*create_spaced_line(char *line, int big_line);

//parsing/map2.c
bool	is_map_valid(t_gm *game);
bool	is_player_valid(t_gm *game);

//start_game.
void	start_game(t_gm *game);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	draw_floor_ceiling(t_gm *game, t_mlx *mlx);
void	raycaster(t_map *map, t_mlx *mlx);

//support.c
void	print_map_values(t_gm *game);