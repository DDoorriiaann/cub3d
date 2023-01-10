#include "cub3d.h"

/*
 mlx_line_horizontal : This function draws a horizontal line filled with
 a given color on an open window. It takes in a pointer to the MinilibX
 instance, a pointer to the open window, the x-coordinate of the start of
 the line, the y-coordinate of the line, the length of the line and the
 color of the line in hexadecimal as input.
 */
void mlx_line_horizontal(t_frame frame, int x, int y, int len, int color)
{
	while (len--) {
		my_mlx_pixel_put(&frame, x++, y, color);
    }
}



/* draw_line_bresenham : This function draws a line on the screen using the
Bresenham line drawing algorithm. It uses the Bresenham algorithm to 
efficiently determine which pixels should be drawn, and draws them one by one
*/
void draw_line_bresenham(t_game *game, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	decision;
	int	x;
	int	y;

	dx = x2 - x1;
	dy = y2 - y1;

	x = x1;
	y = y1;

	// initialize the decision parameter
	decision = 2 * dy - dx;

	while (x < x2)
	{
		if (decision >= 0)
		{
			my_mlx_pixel_put(&game->frame, x, y, 0x0000FF);
			y = y + 1;
			decision = decision + 2 * dy - 2 * dx;
		}
		else
		{
			my_mlx_pixel_put(&game->frame, x, y, 0x0000FF);
			decision = decision + 2 * dy;
		}
		x = x + 1;
	}
}
/* simple line drawing algorithm */

void draw_target(t_game *game, t_player player, int endX, int endY)
{
	double deltaX = (endX - player.x); // 10
	double deltaY = (endY - player.y); // 0
	double pixelX = player.x;
	double pixelY = player.y;
	int color = 0xFF0000;

	pixelX += deltaX;
	pixelY += deltaY;
	mlx_circle_filled(game, pixelX, pixelY, 2, color);
}

/* simple grid drawing algorithm */

void	draw_grid(t_game *game)
{
    for (int x = 0; x <= MINIMAP_SIZE; x++)
	{
        for (int y = 0; y <= MINIMAP_SIZE; y++)
		{
            if (x % GRID_SIZE == 0 || y % GRID_SIZE == 0)
				my_mlx_pixel_put(&game->frame, x, y, 0xFFFFFF);
        }
    }
}