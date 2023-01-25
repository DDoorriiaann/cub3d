#include "cub3d.h"

void	draw_vertical_collision(t_game *game, t_ray *ray,
			t_player player, int ray_count)
{
	ray->depth = ray->depth_vert;
	fisheye_correction(ray, player.angle);
	ray->wall_height = ((WINDOW_HEIGHT / 2) / (ray->depth / 13));
	ray->x = ray->x_vert;
	ray->y = ray->y_vert;
	draw_wall_ray(game, *ray, ray_count);
}

void	init_ray_x_direction(t_ray *ray)
{
	if (ray->cos_a > 0)
	{
		ray->x_vert = ray->x_map + 1;
		ray->dx = 1;
	}
	else
	{
		ray->x_vert = ray->x_map - 1e-6;
		ray->dx = -1;
	}
}

void	vertical_collision_check(t_game *game, t_ray *ray)
{
	int	i;

	init_ray_x_direction(ray);
	ray->depth_vert = (ray->x_vert - ray->orig_x) / ray->cos_a;
	ray->y_vert = ray->orig_y + ray->depth_vert * ray->sin_a;
	ray->delta_depth = ray->dx / ray->cos_a;
	ray->dy = ray->delta_depth * ray->sin_a;
	i = 0;
	while (i < RAY_MAX_DEPTH)
	{
		ray->tile_vert[0] = (int)(ray->x_vert / GRID_UNIT);
		ray->tile_vert[1] = (int)(ray->y_vert / GRID_UNIT);
		if (check_collision(game->map, ray->tile_vert[0], ray->tile_vert[1]))
			break ;
		ray->x_vert += ray->dx;
		ray->y_vert += ray->dy;
		ray->depth_vert += ray->delta_depth;
		i++;
	}
}
