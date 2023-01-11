#include "cub3d.h"

void	raycasting(t_game *game, t_player player)
{
	double	drawn_angle;
	int		ray_count;
	float	step;
	t_ray	ray;

	step = (float)FOV / (float)WINDOW_WIDTH;
	ray_count = WINDOW_WIDTH;
	drawn_angle = player.angle - (FOV / 2);
	while (ray_count >= 0)
	{
		ray.collision = 0;
		ray.distance = 0;
		ray.x = player.x;
		ray.y = player.y;
		while (ray.collision == 0)
		{
			ray.x += cos(drawn_angle);
			ray.y += sin(drawn_angle);
			ray.distance += 1;
			if (game->map.matrix[(int)(ray.y / GRID_UNIT)][(int)(ray.x / GRID_UNIT)] == '1')
				ray.collision = 1;
		}
		draw_line(game, player, (int)ray.x, (int)ray.y);
		drawn_angle += step;
		ray_count--;
	}
}