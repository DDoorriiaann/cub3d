#include "cub3d.h"

/*
mlx_circle_filled : This function draws a filled circle of a given color
on an open window using the Bresenham's circle drawing algorithm. It takes
in a pointer to the MinilibX instance, a pointer to the open window, the
x-coordinate of the center of the circle, the y-coordinate of the center
of the circle, the radius of the circle and the color of the circle in 
hexadecimal as input.
*/

void	draw_disc(t_game *game,
			int x, int y, int r, int color)
{
	int	d;
	int	cx;
	int	cy;

	cx = 0;
	cy = r;
	d = 3 - 2 * r;
	while (cx <= cy)
	{
		draw_line_horizontal(game->frame, x - cy, y + cx, 2 * cy, color);
		draw_line_horizontal(game->frame, x - cy, y - cx, 2 * cy, color);
		draw_line_horizontal(game->frame, x - cx, y - cy, 2 * cx, color);
		draw_line_horizontal(game->frame, x - cx, y + cy, 2 * cx, color);
		if (d < 0)
			d = d + 4 * cx + 6;
		else
		{
			d = d + 4 * (cx - cy) + 10;
			cy--;
		}
		cx++;
	}
}

void draw_minimap(t_game *game, t_frame minimap)
{
	int x;
	int y;

	y = 0;
	while (y < game->minimap.height )
	{
		x = 0;
		while (x < game->minimap.width)
		{
			my_mlx_pixel_put(&game->frame, x , y , get_pixel(minimap, x, y));
			x++;
		}
		y++;
	}
}

/*
 mlx_circle : This function draws a circle of a given color on an open window 
 using the Bresenham's circle drawing algorithm. It takes in a pointer to the 
 MinilibX instance, a pointer to the open window, the x-coordinate of the 
 center of the circle, the y-coordinate of the center of the circle, the radius
 of the circle and the color of the circle in hexadecimal as input.
*/

void mlx_circle(t_frame frame, int x, int y, int r, int color)
{
	int d;
	int cx;
	int cy;

	cx = 0;
	cy = r;
	d = 3 - 2 * r;
	while (cx <= cy)
	{
		my_mlx_pixel_put(&frame, x + cx, y + cy, color);
		my_mlx_pixel_put(&frame, x + cy, y - cx, color);
		my_mlx_pixel_put(&frame, x + cx, y - cy, color);
		my_mlx_pixel_put(&frame, x + cy, y + cx, color);
		my_mlx_pixel_put(&frame, x - cx, y - cy, color);
		my_mlx_pixel_put(&frame, x - cy, y - cx, color);
		my_mlx_pixel_put(&frame, x - cy, y + cx, color);
		my_mlx_pixel_put(&frame, x - cx, y + cy, color);
		if (d < 0)
			d = d + 4 * cx + 6;
		else
		{
			d = d + 4 * (cx - cy) + 10;
			cy--;
		}
		cx++;
	}
}