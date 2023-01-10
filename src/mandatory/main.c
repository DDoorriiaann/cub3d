#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500
#define MINIMAP_SIZE 500
#define GRID_SIZE 50
#define PLAYER_SIZE 5
#define PLAYER_SPEED 3
#define PLAYER_TURN_SPEED M_PI / 4 / 10
#define TRUE 1
#define FALSE 0

void	my_mlx_pixel_put(t_frame *frame, int x, int y, int color)
{
	char	*dst;

	dst = frame->addr + (y * frame->line_length + x * (frame->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*
 mlx_line_horizontal : This function draws a horizontal line filled with a given color on an open window. It takes in a pointer to the MinilibX instance, a pointer to the open window, the x-coordinate of the start of the line, the y-coordinate of the line, the length of the line and the color of the line in hexadecimal as input.
 */
void mlx_line_horizontal(t_frame frame, int x, int y, int len, int color)
{
	while (len--) {
		my_mlx_pixel_put(&frame, x++, y, color);
    }
}



/* draw_line_bresenham : This function draws a line on the screen using the Bresenham line drawing algorithm.  
It uses the Bresenham algorithm to efficiently determine which pixels should be drawn, and draws them one by one
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

/*
mlx_circle_filled : This function draws a filled circle of a given color on an open window using the Bresenham's circle drawing algorithm. It takes in a pointer to the MinilibX instance, a pointer to the open window, the x-coordinate of the center of the circle, the y-coordinate of the center of the circle, the radius of the circle and the color of the circle in hexadecimal as input.
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
void draw_line(t_game *game, int beginX, int beginY, int endX, int endY)
{
	double deltaX = (endX - beginX); // 10
	double deltaY = (endY - beginY); // 0

	//printf ("deltaX: %f", deltaX);
	//printf ("deltaY: %f", deltaY);
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	double pixelX = beginX;
	double pixelY = beginY;
	int color = 0xFF0000;
	
	//while (pixels)
	//{
		pixelX += deltaX;
		pixelY += deltaY;
	mlx_circle_filled(game, pixelX, pixelY, 2, color);
	//	my_mlx_pixel_put(&game->frame, pixelX, pixelY, color);
				--pixels;
	//}
}

/*
 mlx_circle : This function draws a circle of a given color on an open window using the Bresenham's circle drawing algorithm. It takes in a pointer to the MinilibX instance, a pointer to the open window, the x-coordinate of the center of the circle, the y-coordinate of the center of the circle, the radius of the circle and the color of the circle in hexadecimal as input.
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

void	quit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	if (game->frame.img)
		mlx_destroy_image(game->mlx, game->frame.img);
	mlx_do_key_autorepeaton(game->mlx);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int key_press(int key, t_game *game) 
{
	if (key == 119)
		game->player.up = TRUE;
	else if (key == 115)
		game->player.down = TRUE;
	else if (key == 97)
		game->player.left = TRUE;
	else if (key == 100)
		game->player.right = TRUE;
	else if (key == 65307)
		quit_game(game);

	return 0;
}

int	key_release(int key, t_game *game)
{
	if (key == 119)
		game->player.up = FALSE;
	else if (key == 115)
		game->player.down = FALSE;
	else if (key == 97)
		game->player.left = FALSE;
	else if (key == 100)
		game->player.right = FALSE;

	return 0;
}

int	update_game(t_game *game)
{
	static int frame = 0;
	usleep(1000000/60);
	frame = frame + 1;
	if (game->player.up)
	{
		game->player.x -= PLAYER_SPEED * cos(game->player.angle);
		game->player.y -= PLAYER_SPEED * sin(game->player.angle);
	}
	if (game->player.down)
	{
		game->player.x += PLAYER_SPEED * cos(game->player.angle);
		game->player.y += PLAYER_SPEED * sin(game->player.angle);
	}
	if (game->player.left)
		game->player.angle = (game->player.angle - PLAYER_TURN_SPEED);
	if (game->player.right)
		game->player.angle = (game->player.angle + PLAYER_TURN_SPEED);

	// Create image and get address
	game->frame.img = mlx_new_image(game->mlx, 501, 501);
	game->frame.addr = mlx_get_data_addr(game->frame.img, &game->frame.bits_per_pixel, &game->frame.line_length, &game->frame.endian);
	
	if (game->player.angle > 2 * M_PI)
		game->player.angle = 0;
	else if (game->player.angle < 0)
		game->player.angle = 2 * M_PI;
	if (frame % 20 == 0)
	{
		printf("angle: %f\n", game->player.angle);
		printf("line end x: %f \nline end y : %f\n", game->player.x + (cos(game->player.angle) * game->player.line_length), game->player.y + (sin(game->player.angle) * game->player.line_length));
		printf("cos: %f\n", cos(game->player.angle));
		printf("sin: %f\n", sin(game->player.angle));
	}
	// Draw grid
	draw_grid(game);
	// Draw disk
	mlx_circle_filled(game, game->player.x, game->player.y, PLAYER_SIZE, 0x0000FF);
	draw_line(game, game->player.x, game->player.y, game->player.x - (cos(game->player.angle) * game->player.line_length), game->player.y - (sin(game->player.angle) * game->player.line_length));
	// Put image to window
	mlx_put_image_to_window(game->mlx, game->window, game->frame.img, 0, 0);
	if (game->frame.img)
	{
		mlx_destroy_image(game->mlx, game->frame.img);
		game->frame.img = NULL;
	}
	return (0);
}



int main() 
{
    t_game	game;

	// Initialize MinilibX
	game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, WINDOW_WIDTH + 1, WINDOW_HEIGHT + 1, "Minimap");

 	// Initialize disk position
    game.player.x = WINDOW_WIDTH / 2;
    game.player.y = WINDOW_HEIGHT / 2;
	game.player.angle = 0;
	game.player.line_length = 20;
	game.player.up = FALSE;
	game.player.down = FALSE;
	game.player.left = FALSE;
	game.player.right = FALSE;
    game.frame.img = NULL;

	// Set up keyboard events
	mlx_do_key_autorepeatoff(game.mlx);
	mlx_hook(game.window, 2, 1L<<0, key_press, &game);
	mlx_hook(game.window, 3, 1L<<1, key_release, &game);
	mlx_loop_hook(game.mlx, update_game, &game);
	mlx_loop(game.mlx);
    return 0;
}
