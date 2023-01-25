#include "cub3d.h"

void	draw_horizontal_collision(t_game *game, t_ray *ray,
			t_player player, int ray_count)
{
	ray->depth = ray->depth_hor;
	fisheye_correction(ray, player.angle);
	ray->wall_height = ((WINDOW_HEIGHT / 2) / (ray->depth / 13));
	ray->x = ray->x_hor;
	ray->y = ray->y_hor;
	draw_wall_ray(game, *ray, ray_count);
}

void	init_ray_y_direction(t_ray *ray)
{
	if (ray->sin_a > 0)
	{
		ray->y_hor = ray->y_map + 1;
		ray->dy = 1;
	}
	else
	{
		ray->y_hor = ray->y_map - 1e-6;
		ray->dy = -1;
	}
}

void	horizontal_collision_check(t_game *game, t_ray *ray)
{
	int	i;

	init_ray_y_direction(ray);
	ray->depth_hor = (ray->y_hor - ray->orig_y) / ray->sin_a;
	ray->x_hor = ray->orig_x + ray->depth_hor * ray->cos_a;
	ray->delta_depth = ray->dy / ray->sin_a;
	ray->dx = ray->delta_depth * ray->cos_a;
	i = 0;
	while (i < RAY_MAX_DEPTH)
	{
		ray->tile_hor[0] = (int)(ray->x_hor / GRID_UNIT);
		ray->tile_hor[1] = (int)(ray->y_hor / GRID_UNIT);
		if (check_collision(game->map, ray->tile_hor[0], ray->tile_hor[1]))
			break ;
		ray->x_hor += ray->dx;
		ray->y_hor += ray->dy;
		ray->depth_hor += ray->delta_depth;
		i++;
	}
}
