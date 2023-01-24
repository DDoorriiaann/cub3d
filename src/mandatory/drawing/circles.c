#include "cub3d.h"

/*
draw_disc : This function draws a filled circle of a given color
on an open window using the Bresenham's circle drawing algorithm. It takes
in a pointer to the MinilibX instance, a pointer to the open window, the
x-coordinate of the center of the circle, the y-coordinate of the center
of the circle, the radius of the circle and the color of the circle in 
hexadecimal as input.
*/

static void	update_decision(int *decision, int *cx, int *cy)
{
	if (*decision < 0)
		*decision = *decision + 4 * *cx + 6;
	else
	{
		*decision = *decision + 4 * (*cx - *cy) + 10;
		*cy = *cy -1;
	}
}

void	draw_disc(t_game *game,
			int x, int y, int r)
{
	int	decision;
	int	cx;
	int	cy;

	cx = 0;
	cy = r;
	decision = 3 - 2 * r;
	while (cx <= cy)
	{
		draw_line_horizontal(game->minimap.frame,
			x - cy, y + cx, 2 * cy);
		draw_line_horizontal(game->minimap.frame,
			x - cy, y - cx, 2 * cy);
		draw_line_horizontal(game->minimap.frame,
			x - cx, y - cy, 2 * cx);
		draw_line_horizontal(game->minimap.frame,
			x - cx, y + cy, 2 * cx);
		update_decision(&decision, &cx, &cy);
		cx++;
	}
}
