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
		draw_line_horizontal(game->minimap.frame, x - cy, y + cx, 2 * cy, color);
		draw_line_horizontal(game->minimap.frame, x - cy, y - cx, 2 * cy, color);
		draw_line_horizontal(game->minimap.frame, x - cx, y - cy, 2 * cx, color);
		draw_line_horizontal(game->minimap.frame, x - cx, y + cy, 2 * cx, color);
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
	int	player_x;
	int	player_y;
	int	src_x;
	int	src_y;

	y = 0;
	player_x = (int)((game->player.x / 128.0 ) * game->minimap.grid_size);
	player_y = (int)((game->player.y / 128.0) * game->minimap.grid_size);
	src_y = player_y - 75;
	while (y < 150 )
	{
		src_x = player_x - 75;
		x = 0;
		while (x < 150)
		{
			if (get_pixel(game->minimap_mask, x, y) != 0x12ff00)
			{
				if (src_x > 0 && src_y > 0 && src_x < game->minimap.width && src_y < game->minimap.height)
					my_mlx_pixel_put(&game->frame, x + 625 , y + 25, get_pixel(minimap, src_x, src_y));
				else
					my_mlx_pixel_put(&game->frame, x + 625 , y + 25, 0x000000);
			}
			x++;
			src_x++;
		}
		y++;
		src_y++;
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