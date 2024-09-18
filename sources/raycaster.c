/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:10:21 by vivaccar          #+#    #+#             */
/*   Updated: 2024/09/18 14:50:02 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"


void    draw_vertical_line(int x, int draw_start, int draw_end, int color, t_mlx *mlx)
{
    while (draw_start <= draw_end)
    {
        my_mlx_pixel_put(mlx, x, draw_start, color);
        draw_start++;
    }
}

void	raycaster(t_map *map, t_mlx *mlx)
{
    int x;
    double  cam_x; // mapear o valor de todas as colunas da tela entre -1 e 1;
    double  ray_dir_x; // direcao do raio em x
    double  ray_dir_y; // direcao do raio em y
    int     mapX; // posicao x atual do mapa em que o ray esta
    int     mapY; // posicao y atual do mapa em que o ray esta
    double  side_dstc_x; // distancia ate o raio atingir o proximo ponto X
    double  side_dstc_y; // distancia ate o raio atingir o proximo ponto Y
    double  delta_dstc_x; // distancia que o raio viaja de uma linha x ate a proxima linha x
    double  delta_dstc_y; // distancia que o raio viaja de uma linha y ate a proxima linha y
    double  wall_dstc;
    int     step_x; // define o incremento do eixo X dependendo do trajato da raio. 1 ou -1
    int     step_y; // define o incremento do eixo Y dependendo do trajato da raio. 1 ou -1
    int     hit; // flag determinante para saber se o quadrado do mapa que foi atingido e uma parede
    int     side;  // qual lado na parade foi atingido NS or WE

    x = 0;
    while (x < WIDTH)
    {
        cam_x = 2 * x / (double)WIDTH - 1;
        ray_dir_x = map->dirX + map->plane_x * cam_x; // esta parte vai calcular a direcao do raio 
        ray_dir_y = map->dirY + map->plane_y * cam_x;

        mapX = (int)map->plyr_x;
        mapY = (int)map->plyr_y;

        
        delta_dstc_x = (ray_dir_x == 0) ? 1e30 : fabs(1 / ray_dir_x); // calculo para obter a distancia entre os pontos
        delta_dstc_y = (ray_dir_y == 0) ? 1e30 : fabs(1 / ray_dir_y);

        hit = 0;
        

        printf("RayDirX = %f, RayDirY = %f\n", ray_dir_x, ray_dir_y);
        printf("X = %i\n", x);
        // definindo o step do ray
        if (ray_dir_x < 0)
        {
            step_x = -1;
            side_dstc_x = (map->plyr_x - mapX) * delta_dstc_x;
        }
        else // ray_dir_x >= 0
        {
            step_x = 1;
            side_dstc_x = (mapX + 1.0 - map->plyr_x) * delta_dstc_x;
        }
        if (ray_dir_y <= 0)
        {
            step_y = -1;
            side_dstc_y = (map->plyr_y - mapY) * delta_dstc_y;
        }
        else
        {
            step_y = 1;
            side_dstc_y = (mapY + 1 - map->plyr_y) * delta_dstc_y;
        }

        while (!hit)
        {
            if (side_dstc_x < side_dstc_y)
            {
                side_dstc_x += delta_dstc_x;
                mapX += step_x;
                side = 0;
            }
            else
            {
                side_dstc_y += delta_dstc_y;
                mapY += step_y;
                side = 1;
            }
            if (map->matriz[mapX][mapY] == '1')
            {
                printf("Wall hitted X = %i, Y = %i\n", mapX, mapY);
                hit = 1;
            }   
        }

        if (side == 0)
            wall_dstc = side_dstc_x - delta_dstc_x;
        else
            wall_dstc = side_dstc_y - delta_dstc_y;
        int line_size = (int)(HEIGHT / wall_dstc); // tamanho da linha que vai ser desenhada na tela
        int draw_start = -line_size / 2 + HEIGHT / 2;
        if (draw_start < 0)
            draw_start = 0;
        int draw_end = line_size / 2 + HEIGHT / 2;
        if (draw_end >= HEIGHT)
            draw_end = HEIGHT - 1;
        int color = 16753920;
        draw_vertical_line(x, draw_start, draw_end, color, mlx);
/*         if (side == 1 && ray_dir_y < 0)
            draw_vertical_line(x, draw_start, draw_end, 0xFFF000, mlx);
        else if (side == 1 && ray_dir_y > 0)
            draw_vertical_line(x, draw_start, draw_end, 0x00FF00, mlx);
        else if (side == 0 && ray_dir_x < 0)
            draw_vertical_line(x, draw_start, draw_end, 0x0000FF, mlx);
        else
            draw_vertical_line(x, draw_start, draw_end, 0x00FFFF, mlx); */
        x++;
    }
}

