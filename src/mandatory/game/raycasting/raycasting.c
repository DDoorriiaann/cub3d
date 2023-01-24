#include "cub3d.h"



void	raycasting(t_game *game, t_player player)
{
	int		ray_count;
	float	step;
	t_ray	ray;
	int		i;
	int		max_depth;

	step = (((float)FOV / (float)WINDOW_WIDTH));
	ray_count = 0;
	ray.angle = player.angle - (FOV / 2) + 0.0001;
	ray.orig_x = player.x;
	ray.orig_y = player.y;
	ray.x_map = player.x;
	ray.y_map = player.y;
	max_depth = 3000;
	while (ray_count < WINDOW_WIDTH)
	{
			
		 if (ray.angle >= 2 * M_PI)
		 	ray.angle -= 2 * M_PI;
		 else if (ray.angle < 0)
		 	ray.angle += 2 * M_PI;
		ray.collision = 0;
		ray.depth = 0;
		ray.sin_a = sin(ray.angle);
		ray.cos_a = cos(ray.angle);
		//Horizontal collision checks
		if (ray.sin_a > 0)
		{
			ray.y_hor = ray.y_map + 1;
			ray.dy = 1;
		}
		else
		{
			ray.y_hor = ray.y_map - 1e-6;
			ray.dy = -1;
		}
		ray.depth_hor = (ray.y_hor - ray.orig_y) / ray.sin_a;
		ray.x_hor = ray.orig_x + ray.depth_hor * ray.cos_a;

		ray.delta_depth = ray.dy / ray.sin_a;
		ray.dx = ray.delta_depth * ray.cos_a;
		i = 0;
		while (i < max_depth)
		{
			ray.tile_hor[0] = (int)(ray.x_hor / GRID_UNIT);
			ray.tile_hor[1] = (int)(ray.y_hor / GRID_UNIT);
			if (check_collision(game->map, ray.tile_hor[0], ray.tile_hor[1]))
				break;
			ray.x_hor += ray.dx;
			ray.y_hor += ray.dy;
			ray.depth_hor += ray.delta_depth;
			i++;
		}
		//Vertical collision checks
		if (ray.cos_a > 0)
		{
			ray.x_vert = ray.x_map + 1;
			ray.dx = 1;
		}
		else
		{
			ray.x_vert = ray.x_map - 1e-6;
			ray.dx = -1;
		}
		ray.depth_vert = (ray.x_vert - ray.orig_x) / ray.cos_a;
		ray.y_vert = ray.orig_y + ray.depth_vert * ray.sin_a;

		ray.delta_depth = ray.dx / ray.cos_a;
		ray.dy = ray.delta_depth * ray.sin_a;

		i = 0;
		while (i < max_depth)
		{
			ray.tile_vert[0] = (int)(ray.x_vert / GRID_UNIT);
			ray.tile_vert[1] = (int)(ray.y_vert / GRID_UNIT);
			if (check_collision(game->map, ray.tile_vert[0], ray.tile_vert[1]))
				break;
			ray.x_vert += ray.dx;
			ray.y_vert += ray.dy;
			ray.depth_vert += ray.delta_depth;
			i++;
		}
		if (ray.depth_vert < ray.depth_hor)
		{
			ray.depth = ray.depth_vert;
				//Fisheye correction :
			ray.depth = ray.depth * cos(player.angle - ray.angle);
			ray.wall_height = ((WINDOW_HEIGHT / 2) / (ray.depth / 13));
			ray.x = ray.x_vert;
			ray.y = ray.y_vert;
			draw_wall_ray(game, ray, ray_count);
		}
		else
		{
			ray.depth = ray.depth_hor;
			//Fisheye correction :
			ray.depth = ray.depth * cos(player.angle - ray.angle);
			ray.wall_height = ((WINDOW_HEIGHT / 2) / (ray.depth / 13));
			ray.x = ray.x_hor;
			ray.y = ray.y_hor;
			draw_wall_ray(game, ray, ray_count);
		}
		draw_ray(game, game->player, ray);
		ray.angle += step;
		ray_count+=1;	
	}
}