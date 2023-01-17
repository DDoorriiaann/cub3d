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
		mlx_line_horizontal(game->minimap, x - cy, y + cx, 2 * cy, color);
		mlx_line_horizontal(game->minimap, x - cy, y - cx, 2 * cy, color);
		mlx_line_horizontal(game->minimap, x - cx, y - cy, 2 * cx, color);
		mlx_line_horizontal(game->minimap, x - cx, y + cy, 2 * cx, color);
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

// void draw_minimap_texture_line(t_game *game, int x1, int y1, int x2, int y2,int x_offset,int y_offset)
// {
//     int x, y;
//     for (x = x1; x <= x2; x++)
//     {
//         for (y = y1; y <= y2; y++)
//         {
// 			if ((x2 - x1) != 0 && (y2 - y1) != 0)
//             {int texture_x = (x - x1) * (game->map.width * GRID_UNIT) / (x2 - x1);
//             int texture_y = (y - y1) * (game->map.height * GRID_UNIT) / (y2 - y1);
// 			if ((x - x_offset > 0 && x - x_offset < game->map.width * GRID_UNIT) && (y - y_offset > 0 && y - y_offset < game->map.height * GRID_UNIT))
//             	my_mlx_pixel_put(&game->frame, x  + (game->map.width * GRID_UNIT) / 2, y + (game->map.height * GRID_UNIT) / 2, get_pixel(game->minimap,texture_x, texture_y));
// 			else
// 				my_mlx_pixel_put(&game->frame, x  + (game->map.width * GRID_UNIT) / 2, y + (game->map.height * GRID_UNIT) / 2, 0x000000);
//         	}
// 			if (x < 0 || y < 0 || x > game->map.width * GRID_UNIT || y > game->map.height * GRID_UNIT)
// 			{	printf("x = %d, y = %d \n", x, y);
// 				printf("map width = %d, map height = %d \n", game->map.width * GRID_UNIT, game->map.height * GRID_UNIT);}
// 		}
//     }
// }
// void draw_minimap_texture_line(t_game *game, int x1, int y1, int x2, int y2,int x_offset,int y_offset)
// {
//     int x, y;
//     for (y = y1; y <= y2; y++)
//     {
//         for (x = x1; x <= x2; x++)
//         {
//             if ((x2 - x1) != 0 && (y2 - y1) != 0)
//             {
//               //  int texture_x = (x - x1) * (game->minimap.width * GRID_UNIT) / (x2 - x1);
//                // int texture_y = (y - y1) * (game->minimap.height * GRID_UNIT) / (y2 - y1);
//                 //if ((x - x_offset > 0 && x - x_offset < game->minimap.width * GRID_UNIT) && (y - y_offset > 0 && y - y_offset < game->minimap.height * GRID_UNIT))
//               //      my_mlx_pixel_put(&game->frame, ((x - x_offset) + (game->minimap.width * GRID_UNIT) / 2), (y - y_offset + ((game->minimap.height * GRID_UNIT) / 2)), get_pixel(game->minimap,texture_x, texture_y));
//                // else
//                     my_mlx_pixel_put(&game->frame, (x - x_offset)+ (game->minimap.width * GRID_UNIT) / 2 , (y - y_offset) +(game->minimap.height * GRID_UNIT) / 2, 0xFFFFFF);
// 			}
// 		}
// 	}
// }
// void	draw_minimap(t_game *game, int x, int y, int r)
// {
// 	int	d;
// 	int	cx;
// 	int	cy;

// 	cx = 0;
// 	cy = r;
// 	d = 3 - 2 * r;
// 	//int color = 0xFFFFFF;
// 	while (cx <= cy)
// 	{
// 		draw_minimap_texture_line(game, x - cy, y + cx, x + cy, y + cx, x, y);
//         draw_minimap_texture_line(game, x - cy, y - cx, x + cy, y - cx, x, y);
//         draw_minimap_texture_line(game, x - cx, y - cy, x + cx, y - cy, x, y);
//         draw_minimap_texture_line(game, x - cx, y + cy, x + cx, y + cy, x, y);
// 		// draw_protected_line_horizontal(game, game->frame, x - cy, y + cx, 2 * cy, color);
// 		// draw_protected_line_horizontal(game, game->frame, x - cy, y - cx, 2 * cy, color);
// 		// draw_protected_line_horizontal(game, game->frame, x - cx, y - cy, 2 * cx, color);
// 		// draw_protected_line_horizontal(game, game->frame, x - cx, y + cy, 2 * cx, color);
// 		if (d < 0)
// 			d = d + 4 * cx + 6;
// 		else
// 		{
// 			d = d + 4 * (cx - cy) + 10;
// 			cy--;
// 		}
// 		cx++;
// 	}
// }

void draw_minimap(t_game *game, t_frame minimap)
{
	int x;
	int y;

	y = 0;
	while (y < game->map.height * GRID_UNIT)
	{
		x = 0;
		while (x < game->map.width * GRID_UNIT)
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