/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:10:21 by vivaccar          #+#    #+#             */
/*   Updated: 2024/09/24 16:58:26 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"


void    draw_vertical_line(int x, int draw_start, int draw_end, int color, t_mlx *mlx)
{
    while (draw_start <= draw_end)
    {
        my_mlx_pixel_put(mlx, x, draw_start, color);
        draw_start++;
    }
}

void    rays_direction(t_ray *ray, int x)
{
    ray->cam_x = 2 * x / (double)WIDTH - 1;
    ray->ray_dir_x = ray->dirX + ray->plane_x * ray->cam_x;
    ray->ray_dir_y = ray->dirY + ray->plane_y * ray->cam_x;       
}

void    delta_dstc(t_ray *ray)
{
    if (ray->ray_dir_x == 0)
		ray->delta_dstc_x = INT_MAX;
	else
		ray->delta_dstc_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dstc_y = INT_MAX;
	else
		ray->delta_dstc_y = fabs(1 / ray->ray_dir_y);
}

void    step_increment(t_ray *ray)
{
    if (ray->ray_dir_x < 0)
    {
        ray->step_x = -1;
        ray->side_dstc_x = (ray->plyr_x - ray->map_x) * ray->delta_dstc_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dstc_x = (ray->map_x + 1.0 - ray->plyr_x) * ray->delta_dstc_x;
    }
    if (ray->ray_dir_y < 0)
    {
        ray->step_y = -1;
        ray->side_dstc_y = (ray->plyr_y - ray->map_y) * ray->delta_dstc_y;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dstc_y = (ray->map_y + 1 - ray->plyr_y) * ray->delta_dstc_y;
    }
}

void    launch_ray(t_ray *ray, t_map *map)
{
    int hit;

    hit = 0;
    while (!hit)
    {
        if (ray->side_dstc_x < ray->side_dstc_y)
        {
            ray->side_dstc_x += ray->delta_dstc_x;
            ray->map_x += ray->step_x;
            ray->side_hit = 0;
        }
        else
        {
            ray->side_dstc_y += ray->delta_dstc_y;
            ray->map_y += ray->step_y;
            ray->side_hit = 1;
        }
        if (map->matriz[ray->map_y][ray->map_x] == '1')
        {
            //printf("Wall hitted X = %i, Y = %i\n", ray->map_x, ray->map_y);
            hit = 1;
        }    
    }
}

void    get_wall_height_and_draw(t_gm *game, t_ray *ray, int x)
{
    int line_size;
    int first_point;
    int last_point;
    
    if (ray->side_hit == 0)
        ray->wall_dstc = ray->side_dstc_x - ray->delta_dstc_x;
    else
        ray->wall_dstc = ray->side_dstc_y - ray->delta_dstc_y;
    line_size = (int)(HEIGHT / ray->wall_dstc);
    first_point = -line_size / 2 + HEIGHT / 2;
    if (first_point < 0)
        first_point = 0;
    last_point = line_size / 2 + HEIGHT / 2;
    if (last_point >= HEIGHT)
        last_point = HEIGHT -1;
    if (ray->side_hit == 1 && ray->ray_dir_y < 0)
        draw_vertical_line(x, first_point, last_point, 0x0000FF, game->mlx);
    else if (ray->side_hit == 1 && ray->ray_dir_y > 0)
        draw_vertical_line(x, first_point, last_point, 0x00FF00, game->mlx);
    else if (ray->side_hit == 0 && ray->ray_dir_x < 0)
        draw_vertical_line(x, first_point, last_point, 0xFF0000, game->mlx);
    else
        draw_vertical_line(x, first_point, last_point, 0xFFFF00, game->mlx);
}

int raycaster(t_gm *game)
{
    int x;

    x = 0;
    draw_floor_ceiling(game, game->mlx);
    while (x < WIDTH)
    {
        game->ray->map_x = (int)game->ray->plyr_x;
    	game->ray->map_y = (int)game->ray->plyr_y;
        //printf("%i\n", game->ray->map_x);
        //printf("%i\n", game->ray->map_y);
        rays_direction(game->ray, x);
        delta_dstc(game->ray);
        step_increment(game->ray);
        launch_ray(game->ray, game->map);
        get_wall_height_and_draw(game, game->ray, x);
/*         printf("%f\n", game->ray->cam_x);
        printf("%f\n", game->ray->delta_dstc_x);
        printf("%f\n", game->ray->delta_dstc_x);
        printf("%f\n", game->ray->dirX);
        printf("%f\n", game->ray->dirY);
        printf("%i\n", game->ray->map_x);
        printf("%i\n", game->ray->map_y);
        printf("%i\n", game->ray->step_x);
        printf("%i\n", game->ray->step_y);
        printf("%f\n", game->ray->side_dstc_x);
        printf("%f\n", game->ray->side_dstc_y);
        printf("%i\n", game->ray->side_hit);
        printf("%f\n", game->ray->plyr_y);
        printf("%f\n", game->ray->plyr_x);
        printf("%f\n", game->ray->plane_x);
        printf("%f\n", game->ray->plane_y); */
        //exit(1);
        x++;
    }
    draw_mini_map(game);
    mlx_put_image_to_window(game->mlx->cnt, game->mlx->wnd, game->mlx->img, 0, 0);
/*      int     x;
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

    
    printf("Player X: %f, Player Y: %f\n", game->map->plyr_x, game->map->plyr_y);
    x = 0;
    while (x < WIDTH)
    {
        cam_x = 2 * x / (double)WIDTH - 1;
        printf("%f, ", cam_x);
        printf("RAY X: %f\n", ray_dir_x);
        printf("RAY Y: %f\n", ray_dir_y);
        ray_dir_x = game->map->dirX + game->map->plane_x * cam_x; // esta parte vai calcular a direcao do raio 
        ray_dir_y = game->map->dirY + game->map->plane_y * cam_x;

        mapX = (int)game->map->plyr_x;
        mapY = (int)game->map->plyr_y;
        
        if (ray_dir_x == 0)
		    delta_dstc_x = INT_MAX;
	    else
		    delta_dstc_x = fabs(1 / ray_dir_x);
	    if (ray_dir_y == 0)
		    delta_dstc_y = INT_MAX;
	    else
		    delta_dstc_y = fabs(1 / ray_dir_y);

        printf("DELTA DSTC X = %f\n", delta_dstc_x);
        printf("DELTA DSTC Y = %f\n", delta_dstc_y);


        hit = 0;
        
        //printf("RayDirX = %f, RayDirY = %f\n", ray_dir_x, ray_dir_y);
        //printf("X = %i\n", x);
        // definindo o step do ray
        if (ray_dir_x < 0)
        {
            step_x = -1;
            side_dstc_x = (game->map->plyr_x - mapX) * delta_dstc_x;
        }
        else // ray_dir_x >= 0
        {
            step_x = 1;
            side_dstc_x = (mapX + 1.0 - game->map->plyr_x) * delta_dstc_x;
        }
        if (ray_dir_y < 0)
        {
            step_y = -1;
            side_dstc_y = (game->map->plyr_y - mapY) * delta_dstc_y;
        }
        else
        {
            step_y = 1;
            side_dstc_y = (mapY + 1 - game->map->plyr_y) * delta_dstc_y;
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
            if (game->map->matriz[mapY][mapX] == '1')
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
        if (side == 1 && ray_dir_y < 0)
            draw_vertical_line(x, draw_start, draw_end, 0x0000FF, game->mlx);
        else if (side == 1 && ray_dir_y > 0)
            draw_vertical_line(x, draw_start, draw_end, 0x00FF00, game->mlx);
        else if (side == 0 && ray_dir_x < 0)
            draw_vertical_line(x, draw_start, draw_end, 0xFF0000, game->mlx);
        else
            draw_vertical_line(x, draw_start, draw_end, 0xFFFF00, game->mlx);
        x++;
    }
    mlx_put_image_to_window(game->mlx->cnt, game->mlx->wnd, game->mlx->img, 0, 0);  */
    return 0;
}

