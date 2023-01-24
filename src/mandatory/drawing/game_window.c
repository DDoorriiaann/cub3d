#include "cub3d.h"

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

void	draw_floor_and_ceiling(t_frame frame)
{
	draw_floor(frame);
	draw_ceiling(frame);
}
