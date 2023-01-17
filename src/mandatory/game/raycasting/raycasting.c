#include "cub3d.h"

// void	raycasting(t_game *game, t_player player)
// {
// 	double	drawn_angle;
// 	int		ray_count;
// 	float	step;
// 	t_ray	ray;
// 	int		iteration;

// 	step = (((float)FOV / (float)WINDOW_WIDTH));
// 	ray_count = 0;
// 	drawn_angle = player.angle - (FOV / 2);
	
// 	while (ray_count < WINDOW_WIDTH)
// 	{
// 		 if (drawn_angle >= 2 * M_PI)
// 		 	drawn_angle -= 2 * M_PI;
// 		 else if (drawn_angle < 0)
// 		 	drawn_angle += 2 * M_PI;
// 		ray.collision = 0;
// 		ray.distance = 0;
// 		ray.x = player.x;
// 		ray.y = player.y;
// 		ray.angle = drawn_angle * (180 / M_PI);
// 		float first_x_offset_len;
// 		float first_y_offset_len;
// 		float offset_x;
// 		float offset_y;
// 		offset_x = tan(ray.angle) * GRID_UNIT;
// 		offset_y = GRID_UNIT / tan(ray.angle);
// 		if (ray.angle > 0 && ray.angle < 90)
// 		{
// 			ray.x_step = - GRID_UNIT;
// 			ray.y_step = - GRID_UNIT;
// 			first_x_offset_len = (ray.x - (int)ray.x) / sin(ray.angle);
// 			first_y_offset_len = (ray.y - (int)ray.y) / cos(ray.angle);
			
// 		}
// 		else if (ray.angle >= 90 && ray.angle < 180)
// 		{
// 			ray.x_step = GRID_UNIT;
// 			ray.y_step = -GRID_UNIT;
// 			first_x_offset_len = (((int)ray.x + 1) - ray.x) / sin(ray.angle);
// 			first_y_offset_len = (ray.y - (int)ray.y) / cos(ray.angle);
// 		}
// 		else if (ray.angle >= 180 && ray.angle < 270)
// 		{
// 			ray.x_step = GRID_UNIT;
// 			ray.y_step = GRID_UNIT;
// 			first_x_offset_len = (((int)ray.x + 1) - ray.x) / sin(ray.angle);
// 			first_y_offset_len = (((int)ray.y + 1) - ray.y) / cos(ray.angle);
// 		}
// 		else if (ray.angle >= 270 && ray.angle < 360)
// 		{
// 			ray.x_step = -GRID_UNIT;
// 			ray.y_step = GRID_UNIT;
// 			first_x_offset_len = (ray.x - (int)ray.x) / sin(ray.angle);
// 			first_y_offset_len = (((int)ray.y + 1) - ray.y) / cos(ray.angle);
// 		}
// 		if (first_x_offset_len < first_y_offset_len)
// 		{
// 			ray.x += first_x_offset_len * cos(ray.angle);
// 			ray.y += first_x_offset_len * sin(ray.angle);
// 			ray.distance += first_x_offset_len;
// 		}
// 		else
// 		{
// 			ray.x += first_y_offset_len * cos(ray.angle);
// 			ray.y += first_y_offset_len * sin(ray.angle);
// 			ray.distance += first_y_offset_len;
// 		}

// 		draw_line(game, player, (int)ray.x, (int)ray.y);
// 		drawn_angle += step;
// 		ray_count+=1;
// 	}
// }

void	raycasting(t_game *game, t_player player)
{
	double	drawn_angle;
	int		ray_count;
	float	step;
	t_ray	ray;
	int		iteration;

	step = (((float)FOV / (float)WINDOW_WIDTH));
	ray_count = 0;
	drawn_angle = player.angle - (FOV / 2);
	
	while (ray_count < WINDOW_WIDTH)
	{
		 if (drawn_angle >= 2 * M_PI)
		 	drawn_angle -= 2 * M_PI;
		 else if (drawn_angle < 0)
		 	drawn_angle += 2 * M_PI;
		ray.collision = 0;
		ray.distance = 0;
		ray.x = player.x;
		ray.y = player.y;

		if (cos(drawn_angle) > 0)
			ray.x_dir = -1;
		else
			ray.x_dir = 1;
		if (sin(drawn_angle) > 0)
			ray.y_dir = -1;
		else
			ray.y_dir = 1;

		iteration = 2;
		while (ray.collision == 0  && ray.distance < 50)
		{
				ray.x -= cos(drawn_angle) / 64;
				ray.y -= sin(drawn_angle) / 64;
			if (ray.x >= 0 && ray.y >= 0 && ray.x < game->map.width * GRID_UNIT && ray.y < game->map.height * GRID_UNIT)
			{
				if (game->map.matrix[(int)(ray.y / GRID_UNIT)][(int)(ray.x / GRID_UNIT)] == '1')
				{
					ray.collision = 1;
					break ;
				}
			}
			ray.distance = sqrt(((ray.x - player.x) * (ray.x - player.x))  + ((ray.y - player.y) * (ray.y - player.y)));
			//Fisheye correction :
			ray.distance = ray.distance * cos(player.angle - drawn_angle);
		}
		ray.wall_height = ((WINDOW_HEIGHT / 2) / (ray.distance / 13));
		ray.angle = drawn_angle * (180/ M_PI);
		
		draw_wall_ray(game, ray, ray_count);
		mlx_circle_filled(game, game->player.x, game->player.y, PLAYER_SIZE, 0x0000FF);
		draw_line(game, player, (int)ray.x, (int)ray.y);
		drawn_angle += step;
		ray_count+=1;
	}
}