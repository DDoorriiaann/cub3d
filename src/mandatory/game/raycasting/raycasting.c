#include "cub3d.h"



void	raycasting(t_game *game, t_player player)
{
	double	drawn_angle;
	int		ray_count;
	float	step;
	t_ray	ray;
	int		iteration;

	step = (float)FOV / (float)WINDOW_WIDTH;
	ray_count = 0;
	drawn_angle = player.angle - (FOV / 2);
	while (ray_count < WINDOW_WIDTH)
	{
		if (drawn_angle > 2 * M_PI)
			drawn_angle -= 2 * M_PI;
		else if (drawn_angle < 0)
			drawn_angle += 2 * M_PI;
		ray.collision = 0;
		ray.distance = 0;
		ray.x = player.x;
		ray.y = player.y;
		if (cos(drawn_angle >= 0))
			ray.x_dir = -1;
		else
			ray.x_dir = 1;
		if (sin(drawn_angle >= 0))
			ray.y_dir = -1;
		else
			ray.y_dir = 1;
		iteration = 1;
		while (ray.collision == 0 && ray.distance < 257 && iteration < 2)
		{
			//ray.x_offset = (GRID_UNIT / tan(drawn_angle)) * player.x_dir;
			//ray.y_offset = (GRID_UNIT * tan(drawn_angle)) * player.y_dir;
			printf("cur_angle: %f\n", drawn_angle);
			if (iteration == 1)
			{
				printf("ray x_dir: %d\n", ray.x_dir);
				printf("ray y_dir: %d\n", ray.y_dir);
				if (ray.x_dir == 1)
				{
					ray.x_first_offset = (floor(ray.y) + 1 - ray.y) / sin(drawn_angle);
				}
				else
				{
					ray.x_first_offset = ((ray.y / GRID_UNIT) - (floor(ray.y / GRID_UNIT))) / sin(drawn_angle) * GRID_UNIT;
					ray.x_first_offset = 1000;
				}
				if (ray.y_dir == 1)
				{
					ray.y_first_offset = (floor(ray.x) + 1 - ray.x) / sin(drawn_angle);
				}
				else
				{
					//ray.y_first_offset = (ray.x - floor(ray.x) / sin(drawn_angle));
					//ray.y_first_offset = 1000;
					ray.y_first_offset = ((ray.x / GRID_UNIT) - (floor(ray.x / GRID_UNIT))) / sin(drawn_angle) * - GRID_UNIT;
				}
				if (fabsf(ray.x_first_offset) < fabsf(ray.y_first_offset))
				{
					//printf("X IS THE NEAREST \n");
					//printf("Y offset: %f\n", ray.y_first_offset);
					//printf("X offset: %f\n", ray.x_first_offset);
					ray.x -= ray.x_first_offset * cos(drawn_angle);
					ray.y -= ray.x_first_offset * sin(drawn_angle);
				}
				else
				{
					//printf("Y IS THE NEAREST \n");
					//printf("Y offset: %f\n", ray.y_first_offset);
					//printf("X offset: %f\n", ray.x_first_offset);
					ray.x += ray.y_first_offset * cos(drawn_angle);
					ray.y += ray.y_first_offset * sin(drawn_angle);
				}
				// ray.x += ray.x * player.x_dir;
				// ray.y += ray.y * player.y_dir;
				iteration++;
			}
			else
			{
				ray.x -= cos(drawn_angle) ;
				ray.y -= sin(drawn_angle) ;
				//ray.x += ray.x_offset;
				//ray.y += ray.y_offset;
			}
			//printf("ray x : %f", ray.x);
			//printf("ray y : %f", ray.y);
			if (game->map.matrix[(int)(ray.y / GRID_UNIT)][(int)(ray.x / GRID_UNIT)] == '1')
			{	
				ray.collision = 1;
				break ;
			}
			ray.distance = sqrt(((ray.x - player.x) * (ray.x - player.x))  + ((ray.y - player.y) * (ray.y - player.y)));
			//Fisheye correction :
			ray.distance = ray.distance * cos(player.angle - drawn_angle);
			//printf("ray distance : %f\n", ray.distance);
		}
		printf("\n");
		ray.wall_height = ((WINDOW_HEIGHT / 2) / (ray.distance / (GRID_UNIT * 1.7)));
		//printf("ray distance : %f\n", ray.distance);
		//printf("ray wall height : %f\n", ray.wall_height);
		draw_line(game, player, (int)ray.x, (int)ray.y);
		draw_wall_ray(game, ray, ray_count);
		drawn_angle += step;
		ray_count++;
	}
	printf("\n\n\n\n\n");
}