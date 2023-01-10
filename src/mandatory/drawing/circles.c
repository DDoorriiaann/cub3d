#include "cub3d.h"

/*
mlx_circle_filled : This function draws a filled circle of a given color
on an open window using the Bresenham's circle drawing algorithm. It takes
in a pointer to the MinilibX instance, a pointer to the open window, the
x-coordinate of the center of the circle, the y-coordinate of the center
of the circle, the radius of the circle and the color of the circle in 
hexadecimal as input.
*/

void	mlx_circle_filled(t_game *game,
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
		mlx_line_horizontal(game->frame, x - cy, y + cx, 2 * cy, color);
		mlx_line_horizontal(game->frame, x - cy, y - cx, 2 * cy, color);
		mlx_line_horizontal(game->frame, x - cx, y - cy, 2 * cx, color);
		mlx_line_horizontal(game->frame, x - cx, y + cy, 2 * cx, color);
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