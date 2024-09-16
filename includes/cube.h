/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:39:18 by aconceic          #+#    #+#             */
/*   Updated: 2024/09/16 15:45:46 by aconceic         ###   ########.fr       */
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
	char	**coordinates;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	char	player_direction;
    float 	player_position_X;
    float 	player_position_Y;
    float 	plane_x;
    float 	plane_y;
	// ceiling clr
}	t_map;

//Main Struc gm = GaMe.
typedef struct s_gm
{
	int			argc_cpy;
	char		**argv_cpy;
	t_mlx		*mlx;
	t_window	*window;
	t_map		*map;
}	t_gm;

int	main(int argc, char **argv);
bool is_argument_valid(t_gm *game);

//free.c
int		err_msg(char *msg, int int_return);
void    free_game(t_gm *game);

//init.c
int	run_mlx(t_gm *game);
int	init_game_struct(t_gm *game, int argc, char **argv);

//map_parsing.c
int	parse_map(t_gm *game, int argc, char **argv);
