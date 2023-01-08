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
#define DISK_SIZE 5
#define DISK_SPEED 1
#define TRUE 1
#define FALSE 0

void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*
 mlx_line_horizontal : This function draws a horizontal line filled with a given color on an open window. It takes in a pointer to the MinilibX instance, a pointer to the open window, the x-coordinate of the start of the line, the y-coordinate of the line, the length of the line and the color of the line in hexadecimal as input.
 */
void mlx_line_horizontal(t_img_data img, int x, int y, int len, int color)
{
    while (len--) {
        my_mlx_pixel_put(&img, x++, y, color);
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
		mlx_line_horizontal(game->img, x - cy, y + cx, 2 * cy, color);
		mlx_line_horizontal(game->img, x - cy, y - cx, 2 * cy, color);
		mlx_line_horizontal(game->img, x - cx, y - cy, 2 * cx, color);
		mlx_line_horizontal(game->img, x - cx, y + cy, 2 * cx, color);
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
 mlx_circle : This function draws a circle of a given color on an open window using the Bresenham's circle drawing algorithm. It takes in a pointer to the MinilibX instance, a pointer to the open window, the x-coordinate of the center of the circle, the y-coordinate of the center of the circle, the radius of the circle and the color of the circle in hexadecimal as input.
*/

void mlx_circle(void *mlx_ptr, void *win_ptr, int x, int y, int r, int color)
{
	int d;
	int cx;
	int cy;

	cx = 0;
	cy = r;
	d = 3 - 2 * r;
	while (cx <= cy)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x + cx, y + cy, color);
		mlx_pixel_put(mlx_ptr, win_ptr, x + cy, y + cx, color);
		mlx_pixel_put(mlx_ptr, win_ptr, x + cy, y - cx, color);
		mlx_pixel_put(mlx_ptr, win_ptr, x + cx, y - cy, color);
		mlx_pixel_put(mlx_ptr, win_ptr, x - cx, y - cy, color);
		mlx_pixel_put(mlx_ptr, win_ptr, x - cy, y - cx, color);
		mlx_pixel_put(mlx_ptr, win_ptr, x - cy, y + cx, color);
		mlx_pixel_put(mlx_ptr, win_ptr, x - cx, y + cy, color);
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
				mlx_pixel_put(game->mlx, game->window, x, y, 0xFFFFFF);
        }
    }
}


int key_press(int key, t_game *game) 
{
	printf("pressed: %i\n", key);
    // Update key state
    switch (key) {
        case 119: // Up arrow
			game->player.up = TRUE;
            break;
        case 115: // Down arrow
			game->player.down = TRUE;
            break;
        case 97: // Left arrow
			game->player.left = TRUE;
            break;
        case 100: // Right arrow
			game->player.right = TRUE;
            break;
    }
    return 0;
}

int	key_release(int key, t_game *game)
{
	printf("released: %i\n", key);
    // Update key state
    switch (key) {
        case 119: // Up arrow
			game->player.up = FALSE;
            break;
        case 115: // Down arrow
			game->player.down = FALSE;
            break;
        case 97: // Left arrow
			game->player.left = FALSE;
            break;
        case 100: // Right arrow
			game->player.right = FALSE;
            break;
    }
    return 0;
}

int	update_game(t_game *game)
{
	usleep(1000000/24);
	if (game->player.up)
		game->player.y -= DISK_SPEED;
	if (game->player.down)
		game->player.y += DISK_SPEED;
	if (game->player.left)
		game->player.x -= DISK_SPEED;
	if (game->player.right)
		game->player.x += DISK_SPEED;
	game->img.img = mlx_new_image(game->mlx, 500, 500);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	
	// Clear window
	mlx_clear_window(game->mlx, game->window);
	// Draw grid
//	draw_grid(game);
	// Draw disk
	mlx_circle_filled(game, game->player.x, game->player.y, DISK_SIZE, 0x0000FF);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	mlx_destroy_image(game->mlx, &game->img);
	return (0);
}

int main() 
{
    t_game	game;
	game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, WINDOW_WIDTH + 1, WINDOW_HEIGHT + 1, "Minimap");

 	// Initialize disk position
    game.player.x = WINDOW_WIDTH / 2;
    game.player.y = WINDOW_HEIGHT / 2;
	game.player.up = FALSE;
	game.player.down = FALSE;
	game.player.left = FALSE;
	game.player.right = FALSE;
    
	// Draw first frame
	//draw_grid(&game);
//	mlx_circle_filled(&game, game.player.x, game.player.y, DISK_SIZE, 0x0000FF);
	
	// Set up keyboard events
	mlx_do_key_autorepeatoff(game.mlx);
	mlx_hook(game.window, 2, 1L<<0, key_press, &game);
	mlx_hook(game.window, 3, 1L<<1, key_release, &game);
	mlx_loop_hook(game.mlx, update_game, &game);
	mlx_loop(game.mlx);
    return 0;
}
