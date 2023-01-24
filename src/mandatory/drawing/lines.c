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

int	get_fogged_color(float distance, int color)
{
	int		fogged_color;
	int		r;
	int		g;
	int		b;
	float	fog;

	fog = 1.0 - (distance / 10000.0);
	if (fog < 0)
		fog = 0;
	if (fog > 1)
		fog = 1;
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = (int)(r * fog);
	g = (int)(g * fog);
	b = (int)(b * fog);
	fogged_color = (r << 16) | (g << 8) | b;
	return (fogged_color);
}

void	init_trace(t_game *game, t_player player, t_raydraw *trace, t_ray ray)
{
	trace->distance = 1;
	trace->x = (int)((player.x / 128.0) * game->minimap.grid_size);
	trace->y = (int)((player.y / 128.0) * game->minimap.grid_size);
	trace->x2 = (int)((ray.x / 128.0) * game->minimap.grid_size);
	trace->y2 = (int)((ray.y / 128.0) * game->minimap.grid_size);
	trace->delta_x = abs(trace->x2 - trace->x);
	trace->delta_y = abs(trace->y2 - trace->y);
	if (trace->x < trace->x2)
		trace->step_x = 1;
	else
		trace->step_x = -1;
	if (trace->y < trace->y2)
		trace->step_y = 1;
	else
		trace->step_y = -1;
	if (trace->delta_x > trace->delta_y)
		trace->err = (trace->delta_x) / 2;
	else
		trace->err = -(trace->delta_y) / 2;
}

void	draw_decision(t_raydraw *trace)
{
	if (trace->err2 > -trace->delta_x)
	{
		trace->err -= trace->delta_y;
		trace->x += trace->step_x;
	}
	if (trace->err2 < trace->delta_y)
	{
		trace->err += trace->delta_x;
		trace->y += trace->step_y;
	}
}

void	draw_ray(t_game *game, t_player player, t_ray ray)
{
	t_raydraw	trace;

	init_trace(game, player, &trace, ray);
	while (1)
	{
		if (trace.x < game->minimap.width && trace.y < game->minimap.height
			&& trace.x > 0 && trace.y > 0)
			my_mlx_pixel_put(&game->minimap.frame, trace.x, trace.y,
				get_fogged_color((trace.distance * trace.distance) * 2,
					0xFF0000));
		else
			break ;
		if (trace.x == trace.x2 && trace.y == trace.y2)
			break ;
		trace.err2 = trace.err;
		draw_decision(&trace);
		trace.distance++;
	}
}

void	draw_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->minimap.grid_size)
	{
		j = 0;
		while (j < game->minimap.grid_size)
		{
			my_mlx_pixel_put(&game->minimap.frame, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

int	get_texture_pixel(t_ray ray, t_texture texture, int wall_y)
{
	int		texture_x;
	int		texture_y;
	char	*data;

	texture_y = texture.height - (int)((wall_y / ray.wall_height)
			* texture.height);
	if (ray.collision == 1)
		texture_x = (int)(((ray.x / GRID_UNIT - (int)ray.x / GRID_UNIT))
				* texture.width);
	else
		texture_x = (int)(((ray.y / GRID_UNIT - (int)ray.y / GRID_UNIT))
				* texture.width);
	data = texture.addr + (texture_y * texture.line_len
			+ texture_x * (texture.bpp / 8));
	return (*(int *)data);
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
			color = get_texture_pixel(ray, game->textures.south, wall_y);
	}	
	else
	{
		ray.collision = 2;
		if ((int)ray.x > (int)(player.x))
			color = get_texture_pixel(ray, game->textures.west, wall_y);
		else
			color = get_texture_pixel(ray, game->textures.east, wall_y);
	}
	return (color);
}

void	draw_floor(t_frame frame)
{
	int	y;
	int	x;
	int	color;
	int	distance;

	y = WINDOW_HEIGHT;
	distance = 0;
	while (y > WINDOW_HEIGHT / 2)
	{
		x = 0;
		color = get_fogged_color((distance * distance) / 8, 0x4F4F4F);
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(&frame, x, y, color);
			x++;
		}
		distance++;
		y--;
	}
}

void	draw_ceiling(t_frame frame)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		x = 0;
		color = get_fogged_color((y * y) / 8, 0x1F1F1F);
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(&frame, x, y, color);
			x++;
		}
		y++;
	}
}

void draw_floor_and_ceiling(t_frame frame)
{
	draw_floor(frame);
	draw_ceiling(frame);
}

void draw_wall_ray(t_game *game, t_ray ray, int ray_count)
{
	float		bottom;
	float		top;
	int			fogged_color;
	int			color;
	int			wall_y;

	ray.wall_height *= 25;
	bottom = WINDOW_HEIGHT / 2 + (ray.wall_height / 2);
	top = bottom - ray.wall_height;
	while (bottom > top)
	{
		wall_y = (bottom - WINDOW_HEIGHT / 2
				+ (ray.wall_height / 2)) - ray.wall_height;
		color = wall_color(ray, game->player, game, -wall_y);
		fogged_color = get_fogged_color(ray.depth * 5, color);
		if (ray.depth > 2500)
			fogged_color = 0x000000;
		if (bottom > 0 && bottom < WINDOW_HEIGHT)
			my_mlx_pixel_put(&game->frame, (int)ray_count,
				(int)bottom, fogged_color);
		bottom--;
	}
}

void	draw_map(t_game *game)
{
	int			x;
	int			y;
	int			cell_nb;
	t_minimap	minimap;

	minimap = game->minimap;
	cell_nb = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			cell_nb++;
			if (game->map.matrix[y][x] == '1')
				draw_square(game, x * minimap.grid_size,
					y * minimap.grid_size, 0xFFFFFF);
			x++;
		}
		y++;
	}
}
