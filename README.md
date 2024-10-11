# Cub3D

## Introduction
The Cub3D project at 42 is an introduction to 3D graphics development using the technique of raycasting. The goal is to create a first-person game similar to the classic Wolfenstein 3D, where the player navigates through a maze and views the environment in a 3D perspective, even though the map is represented as a 2D grid. This project provides a practical way to learn the fundamentals of 3D rendering and graphics manipulation using MiniLibX, a small graphical library provided by the school. The implementation involves setting up a raycasting system that simulates the 3D effect by casting rays from the player's position to detect walls and render them accordingly.

## Technologies
- **Programming Language**: C
- **Library**: MiniLibX (provided by the 42 school)
- **Ambient**: Linux.

## Map Configuration

The program must take as a first argument a scene description file with the `.cub` extension. This file describes the map and the various elements needed for the game to function properly.

### Map Composition
- The map must be composed of only 6 possible characters:
  - `0` for an empty space.
  - `1` for a wall.
  - `N, S, E, W` for the player’s start position and orientation (North, South, East, or West).

- Example of a simple valid map:
```bash
1111111111
1001000001
1010000011
1100N00111
1111111111
```

### Map Requirements
- The map must be **closed** or **surrounded by walls** (`1`). If the map is not properly enclosed, the program must return an error.
- Except for the map content (which is always the last element), each type of information can be separated by one or more empty lines.
- Each type of element, except for the map, can be placed in any order in the file.
- Each element (except the map) begins with an identifier, followed by the relevant information for that element. These identifiers and their details are listed below:

### Elements and Identifiers
1. **Textures**: Textures for each direction (North, South, East, and West) are specified as follows:
 - North Texture:
   ```
   NO ./path_to_the_north_texture
   ```
   - Identifier: `NO`
   - Path: Path to the north texture file.

 - South Texture:
   ```
   SO ./path_to_the_south_texture
   ```
   - Identifier: `SO`
   - Path: Path to the south texture file.

 - West Texture:
   ```
   WE ./path_to_the_west_texture
   ```
   - Identifier: `WE`
   - Path: Path to the west texture file.

 - East Texture:
   ```
   EA ./path_to_the_east_texture
   ```
   - Identifier: `EA`
   - Path: Path to the east texture file.

2. **Colors**: Floor and ceiling colors are defined using RGB values in the range `[0,255]`:
 - Floor Color:
   ```
   F 220,100,0
   ```
   - Identifier: `F`
   - RGB Values: `220, 100, 0`

 - Ceiling Color:
   ```
   C 225,30,0
   ```
   - Identifier: `C`
   - RGB Values: `225, 30, 0`
  
## Raycaster
Raycasting is a rendering technique used in 2D games to create a 3D perspective. The basic idea is to cast rays from the player's point of view into the game world, one for each vertical line of the screen. Each ray travels until it hits a wall, determining the distance to that wall. This distance is then used to draw vertical strips on the screen, simulating the depth and perspective of a 3D environment.

## Key Variables before start
Before diving into the code, let's understand the key variables used in the raycaster:

- **dir_x** and **dir_y**: These represent the player's viewing direction in the 2D space. If the player is looking north, `dir_y` will be `-1` (since y-coordinates decrease as you move up), and `dir_x` will be `0` (no horizontal movement). If the player is looking east, `dir_x` will be `1`, and `dir_y` will be `0`.
- **plane_x** and **plane_y**: These define the camera plane perpendicular to the direction vector, controlling the field of view. For example, if the player is facing north, `plane_x` is `0.66` and `plane_y` is `0` (extending left and right horizontally). If the player is facing east, `plane_x` is `0` and `plane_y` is `0.66` (extending up and down vertically).
- **cam_x**: This variable represents the x-coordinate of the camera for each vertical screen line, ranging from -1 (left) to 1 (right). It's used to calculate the direction of each ray.

After that, we perform the following sequence of calculations for each column x of the screen:

### 1. `rays_direction(t_ray *ray, int x)`
This function calculates the direction of the ray for each vertical strip (`x`) on the screen:

```c
void rays_direction(t_ray *ray, int x)
{
    ray->cam_x = 2 * x / (double)WIDTH - 1;
    ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->cam_x;
    ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->cam_x;
}
```
### 2. delta_dstc(t_ray *ray)
This function calculates the distance the ray must travel in the x and y directions before crossing a grid line:

```c
void delta_dstc(t_ray *ray)
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
```
The function sets delta_dstc_x and delta_dstc_y to the absolute value of the reciprocal of the ray direction. This represents the distance a ray needs to travel horizontally or vertically to cross a grid line. If the ray direction is zero, it prevents division by zero by setting the distance to the maximum integer value (INT_MAX).


//https://github.com/abdeljalil-salhi/cub3d/tree/main

//https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf

//make re && clear && valgrind --leak-check=full --track-fds=yes ./cub3D maps/example.cub



//make re && clear && valgrind --leak-check=full ./cub3D maps/example.cub

//https://www.spriters-resource.com
