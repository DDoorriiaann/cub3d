#include "cub3d.h"

void	draw_floor(t_frame frame, int floor_color)
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
		color = get_fogged_color((distance * distance) / 8, floor_color);
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(&frame, x, y, color);
			x++;
		}
		distance++;
		y--;
	}
}

void	draw_ceiling(t_frame frame, int ceiling_color)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		x = 0;
		color = get_fogged_color((y * y) / 8, ceiling_color);
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(&frame, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_floor_and_ceiling(t_frame frame,
		int ceiling_color, int floor_color)
{
	draw_floor(frame, floor_color);
	draw_ceiling(frame, ceiling_color);
}
