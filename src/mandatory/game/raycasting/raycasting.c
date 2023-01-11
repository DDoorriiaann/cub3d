#include "cub3d.h"



void	raycasting(t_game *game, t_player player)
{
	double	drawn_angle;
	int		ray_count;
	float	step;
	t_ray	ray;

	step = (float)FOV / (float)WINDOW_WIDTH;
	ray_count = 0;
	drawn_angle = player.angle - (FOV / 2);
	while (ray_count < WINDOW_WIDTH)
	{
		ray.collision = 0;
		ray.distance = 0;
		ray.x = player.x;
		ray.y = player.y;
		while (ray.collision == 0)
		{
			ray.x -= cos(drawn_angle);
			ray.y -= sin(drawn_angle);
			ray.distance = sqrt(pow(ray.x - player.x, 2) + pow(ray.y - player.y, 2));
			//Fisheye correction :
			ray.distance = ray.distance * cos(player.angle - drawn_angle);
			if (game->map.matrix[(int)(ray.y / GRID_UNIT)][(int)(ray.x / GRID_UNIT)] == '1')
				ray.collision = 1;
		}
		ray.wall_height = ((WINDOW_HEIGHT / 2) / (ray.distance / (GRID_UNIT * 1.7)));
		printf("ray distance : %f\n", ray.distance);
		printf("ray wall height : %f\n", ray.wall_height);
		draw_line(game, player, (int)ray.x, (int)ray.y);
		draw_wall_ray(game, ray, ray_count);
		drawn_angle += step;
		ray_count++;
	}
}