#include "cub3d.h"

void	reset_ray(t_ray *ray, t_player player)
{
	ray->orig_x = player.x;
	ray->orig_y = player.y;
	ray->x_map = player.x;
	ray->y_map = player.y;
	ray->collision = 0;
	ray->depth = 0;
	ray->sin_a = sin(ray->angle);
	ray->cos_a = cos(ray->angle);
}

void	fisheye_correction(t_ray *ray, double player_angle)
{
	ray->depth = ray->depth * cos(player_angle - ray->angle);
}

void	raycasting(t_game *game, t_player player)
{
	int		ray_count;
	double	step;
	t_ray	ray;

	step = (((double)FOV / (double)WINDOW_WIDTH));
	ray_count = 0;
	ray.angle = player.angle - (FOV / 2) + 0.0001;
	while (ray_count < WINDOW_WIDTH)
	{
		if (ray.angle >= 2 * M_PI)
			ray.angle -= 2 * M_PI;
		else if (ray.angle < 0)
			ray.angle += 2 * M_PI;
		reset_ray(&ray, player);
		horizontal_collision_check(game, &ray);
		vertical_collision_check(game, &ray);
		if (ray.depth_vert < ray.depth_hor)
			draw_vertical_collision(game, &ray, player, ray_count);
		else
			draw_horizontal_collision(game, &ray, player, ray_count);
		draw_ray(game, game->player, ray);
		ray.angle += step;
		ray_count += 1;
	}
}
