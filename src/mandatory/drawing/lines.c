#include "cub3d.h"

/*
 mlx_line_horizontal : This function draws a horizontal line filled with
 a given color on an open window. It takes in a pointer to the MinilibX
 instance, a pointer to the open window, the x-coordinate of the start of
 the line, the y-coordinate of the line, the length of the line and the
 color of the line in hexadecimal as input.
 */
void mlx_line_horizontal(t_frame minimap, int x, int y, int len, int color)
{
	while (len--) {
		my_mlx_pixel_put(&minimap, x++, y, color);
    }
}

void draw_protected_line_horizontal(t_game *game, t_frame minimap, int x, int y, int len, int color)
{
	while (len--) {
		if (x > 0 && y > 0 && x < game->map.width && y < game->map.height)
			my_mlx_pixel_put(&minimap, x++, y, color);
    }
}



/* draw_line_bresenham : This function draws a line on the screen using the
Bresenham line drawing algorithm. It uses the Bresenham algorithm to 
efficiently determine which pixels should be drawn, and draws them one by one
*/
// void draw_line_bresenham(t_game *game, int x1, int y1, int x2, int y2)
// {
// 	int	dx;
// 	int	dy;
// 	int	decision;
// 	int	x;
// 	int	y;

// 	dx = x2 - x1;
// 	dy = y2 - y1;

// 	x = x1;
// 	y = y1;

// 	// initialize the decision parameter
// 	decision = 2 * dy - dx;

// 	while (x < x2)
// 	{
// 		if (decision >= 0)
// 		{
// 			my_mlx_pixel_put(&game->frame, x, y, 0x0000FF);
// 			y = y + 1;
// 			decision = decision + 2 * dy - 2 * dx;
// 		}
// 		else
// 		{
// 			my_mlx_pixel_put(&game->frame, x, y, 0x0000FF);
// 			decision = decision + 2 * dy;
// 		}
// 		x = x + 1;
// 	}
// }

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
        if (x < GRID_UNIT * game->map.width && y < GRID_UNIT * game->map.height && x > 0 && y > 0)
			my_mlx_pixel_put(&game->minimap, x, y, 0xFF0000);
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

void	draw_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= GRID_UNIT)
	{
		j = 0;
		while (j <= GRID_UNIT)
		{
			my_mlx_pixel_put(&game->minimap, x + j, y + i, color);
			j++;
		}
		i++;
	}
	
}
int	get_fogged_color(float distance, int color)
{
	int		fogged_color;
	
	int		r;
	int		g;
	int		b;

	if (distance > 49)
		distance = 50;
	r = (color >> 16) & 0xFF - ((int)(distance * 255) / 50);
	g = (color >> 8) & 0xFF - ((int)(distance * 255) / 50);
	b = color & 0xFF - ((int)(distance * 255) / 50);
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	fogged_color = r << 16 | g << 8 | b;
	return (fogged_color);
}


int	wall_color(t_ray ray, t_player player)
{
	int color;
	color = 0xFFFFFF;
 
	float horizontal_distance = 0, vertical_distance = 0;

	if (ray.angle >= 0 && ray.angle < 90)
	{
    horizontal_distance = (int)(ray.x / GRID_UNIT) * GRID_UNIT - ray.x;
    vertical_distance = (int)(ray.y / GRID_UNIT) * GRID_UNIT - ray.y;
	}
	else if (ray.angle >= 90 && ray.angle < 180)
	{
    horizontal_distance = (int)(ray.x / GRID_UNIT) * GRID_UNIT + GRID_UNIT - ray.x;
    vertical_distance = (int)(ray.y / GRID_UNIT) * GRID_UNIT - ray.y;
	
	}
	else if (ray.angle >= 180 && ray.angle < 270)
	{
    horizontal_distance = (int)(ray.x / GRID_UNIT) * GRID_UNIT + GRID_UNIT - ray.x;
    vertical_distance = (int)(ray.y / GRID_UNIT) * GRID_UNIT + GRID_UNIT - ray.y;
	} 
	else if (ray.angle >= 270 && ray.angle < 360)
	{
	horizontal_distance = (int)(ray.x / GRID_UNIT) * GRID_UNIT - ray.x;
	vertical_distance = (int)(ray.y / GRID_UNIT) * GRID_UNIT + GRID_UNIT - ray.y;
	}

	if (fabs(horizontal_distance) < fabs(vertical_distance)) 
	{
    // collision horizontale
		if ((int)ray.y > (int)(player.y))
			color = 0xFF00FF;
		else
			color = 0x00FFFF;
	} else {
		// collision verticale
		if ((int)ray.x > (int)(player.x))
			color = 0x0000FF;
		else
			color = 0xFFFF00;
	}
	return (color);
}

void draw_wall_ray(t_game *game, t_ray ray, int ray_count)
{
	float	bottom;
	float	top;
	int		fogged_color;
	int 	color;

	if (ray.distance > 49)
		return ;
	bottom = WINDOW_HEIGHT / 2 + (ray.wall_height / 2);
	//printf("bottom: %d", bottom);
	top = bottom - ray.wall_height;
	//printf("top: %d", top);
//	if (ray.distance < 49)
		color = wall_color(ray, game->player);
	// else
	// 	color = 0x000000;
	fogged_color = get_fogged_color(ray.distance, color);
	//printf("ray distance : %f\n", ray.distance);
	//fogged_color = color;
	while (bottom > top)
	{
		if (bottom > 0 && bottom < WINDOW_HEIGHT && (bottom > (GRID_UNIT * game->map.height) / 2 || ray_count > (GRID_UNIT * game->map.width) / 2))
			my_mlx_pixel_put(&game->frame, (int)ray_count, (int)bottom, fogged_color);
		bottom--;
	}
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;
	int	cell_nb = 0;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			cell_nb++;
			if(game->map.matrix[y][x] == '1')
				draw_square(game, x * GRID_UNIT, y * GRID_UNIT, 0xFFFFFF);
			else
				draw_square(game, x * GRID_UNIT, y * GRID_UNIT, 0x000000);
			x++;
		}
		y++;
	}
}




/* simple grid drawing algorithm */

void	draw_grid(t_game *game)
{
    for (int y = 0; y <= game->map.height * GRID_UNIT; y++)
	{
        for (int x = 0; x <= game->map.width * GRID_UNIT; x++)
		{
            if (x % GRID_UNIT == 0 || y % GRID_UNIT == 0)
				my_mlx_pixel_put(&game->minimap, x, y, 0x00FF00);
        }
    }
}