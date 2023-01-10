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

void draw_line(t_game *game, t_player player, int x2, int y2)
{
    int delta_x;
	int delta_y;
	int step_x;
	int step_y;
	int x;
	int y;
	int err;
	int err2;

	x = (int)player.x;
	y = (int)player.y;
    delta_x = abs(x2 - x);
    delta_y = abs(y2 - y);
    step_x = x < x2 ? 1 : -1;
    step_y = y < y2 ? 1 : -1;
    err = (delta_x > delta_y ? delta_x : - delta_y) / 2;

    while (1)
    {
        if (x < WINDOW_WIDTH && y < WINDOW_HEIGHT && x > 0 && y > 0)
			my_mlx_pixel_put(&game->frame, x, y, 0xFF0000);
		else
			break ;
        if (x == x2 && y == y2)
            break ;
        err2 = err;
        if (err2 > - delta_x)
        {
            err -= delta_y;
            x += step_x;
        }
        if (err2 < delta_y)
        {
            err += delta_x;
            y += step_y;
        }
    }
}
/* simple line drawing algorithm */


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