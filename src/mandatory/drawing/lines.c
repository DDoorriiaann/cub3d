#include "cub3d.h"

/*
 mlx_line_horizontal : This function draws a horizontal line filled with
 a given color on an open window. It takes in a pointer to the MinilibX
 instance, a pointer to the open window, the x-coordinate of the start of
 the line, the y-coordinate of the line, the length of the line and the
 color of the line in hexadecimal as input.
 */
void	draw_line_horizontal(t_frame minimap, int x, int y, int len)
{
	int	color;

	color = 0xFF0000;
	while (len)
	{
		my_mlx_pixel_put(&minimap, x++, y, color);
		len--;
	}
}

int	wall_color(t_ray ray, t_player player, t_game *game, int wall_y)
{
	int	color;

	if (ray.depth_hor < ray.depth_vert)
	{
		ray.collision = 1;
		if ((int)ray.y > (int)(player.y))
			color = get_texture_pixel(ray, game->textures.north, wall_y);
		else
		{
			if (game->bonus == TRUE)
				color = get_texture_pixel(ray, game->textures.bonus[game->anim_frame_nb], wall_y);
			else
				color = get_texture_pixel(ray, game->textures.south, wall_y);
		}	
	}	
	else
	{
		ray.collision = 2;
		if ((int)ray.x > (int)(player.x))
			color = get_texture_pixel(ray, game->textures.west, wall_y);
		else
		{
			if (game->bonus == TRUE)
				color = get_texture_pixel(ray, game->textures.bonus[game->anim_frame_nb], wall_y);
			else
				color = get_texture_pixel(ray, game->textures.east, wall_y);
		}
	}
	return (color);
}

void	draw_wall_ray(t_game *game, t_ray ray, int ray_count)
{
	int			bottom;
	int			top;
	int			fogged_color;
	int			color;
	int			wall_y;
	int			dy;

	if (ray.depth > 2500)
		return ;
	ray.wall_height = round(ray.wall_height * 25);
	bottom = WINDOW_HEIGHT / 2 + (ray.wall_height / 2);
	top = bottom - ray.wall_height;
	dy = -(WINDOW_HEIGHT / 2) +((ray.wall_height / 2) - (ray.wall_height));
	while (bottom > top)
	{
		if (bottom >= 0 && bottom < WINDOW_HEIGHT)
		{
			wall_y = (bottom + dy) * -1;
			color = wall_color(ray, game->player, game, wall_y);
			//color = 0xFF0000;
			fogged_color = get_fogged_color(ray.depth * 5, color);
			//fogged_color = color;
			my_mlx_pixel_put(&game->frame, (int)ray_count,
				(int)bottom, fogged_color);
		}
		bottom--;
	}
}
