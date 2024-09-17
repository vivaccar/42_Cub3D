/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:10:21 by vivaccar          #+#    #+#             */
/*   Updated: 2024/09/17 20:20:45 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"


void	raycaster(t_gm *game)
{
    int x;
    double cam_x; // mapear o valor de todas as colunas da tela entre -1 e 1;
    double ray_dir_x;
    double ray_dir_y;


    x = 0;
    while (x < WIDTH)
    {
        cam_x = 2 * x / (double)WIDTH -1;
        ray_dir_x = game->map->dirX + game->map->plane_x * cam_x;
        ray_dir_y = game->map->dirY + game->map->plane_y * cam_x;
        //mlx_destroy_image(game->map.ml)
    }
}

// 1st -> determinar a direcao do raio a partir da direcao e da posicao do player

// 2nd ->