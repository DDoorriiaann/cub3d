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
#define DISK_SPEED 5

/*
 mlx_line_horizontal : This function draws a horizontal line filled with a given color on an open window. It takes in a pointer to the MinilibX instance, a pointer to the open window, the x-coordinate of the start of the line, the y-coordinate of the line, the length of the line and the color of the line in hexadecimal as input.
 */
void mlx_line_horizontal(void *mlx_ptr, void *win_ptr, int x, int y, int len, int color)
{
    while (len--) {
        mlx_pixel_put(mlx_ptr, win_ptr, x++, y, color);
    }
}

/*
mlx_circle_filled : This function draws a filled circle of a given color on an open window using the Bresenham's circle drawing algorithm. It takes in a pointer to the MinilibX instance, a pointer to the open window, the x-coordinate of the center of the circle, the y-coordinate of the center of the circle, the radius of the circle and the color of the circle in hexadecimal as input.
*/

void mlx_circle_filled(void *mlx_ptr, void *win_ptr, int x, int y, int r, int color)
{
    int d;
    int cx = 0;
    int cy = r;

    d = 3 - 2 * r;
    while (cx <= cy) {
        mlx_line_horizontal(mlx_ptr, win_ptr, x - cy, y + cx, 2 * cy, color);
        mlx_line_horizontal(mlx_ptr, win_ptr, x - cy, y - cx, 2 * cy, color);
        mlx_line_horizontal(mlx_ptr, win_ptr, x - cx, y - cy, 2 * cx, color);
        mlx_line_horizontal(mlx_ptr, win_ptr, x - cx, y + cy, 2 * cx, color);
        if (d < 0) {
            d = d + 4 * cx + 6;
        }
        else {
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
    int cx = 0;
    int cy = r;

    d = 3 - 2 * r;
    while (cx <= cy) {
        mlx_pixel_put(mlx_ptr, win_ptr, x + cx, y + cy, color);
        mlx_pixel_put(mlx_ptr, win_ptr, x + cy, y + cx, color);
        mlx_pixel_put(mlx_ptr, win_ptr, x + cy, y - cx, color);
        mlx_pixel_put(mlx_ptr, win_ptr, x + cx, y - cy, color);
        mlx_pixel_put(mlx_ptr, win_ptr, x - cx, y - cy, color);
        mlx_pixel_put(mlx_ptr, win_ptr, x - cy, y - cx, color);
        mlx_pixel_put(mlx_ptr, win_ptr, x - cy, y + cx, color);
        mlx_pixel_put(mlx_ptr, win_ptr, x - cx, y + cy, color);
        if (d < 0) {
            d = d + 4 * cx + 6;
        }
        else {
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

void	move_player(t_game *game)
{
		// Clear window
		mlx_clear_window(game->mlx, game->window);
		// Draw grid
		draw_grid(game);
		// Draw disk
		mlx_circle_filled(game->mlx, game->window, game->player.x, game->player.y, DISK_SIZE, 0x0000FF);
}

int key_press(int key, void *param) {
	t_game		*game;
	
	game = param;
	printf("pressed: %i\n", key);
    // Update key state
    switch (key) {
        case 119: // Up arrow
			game->player.y -= DISK_SPEED;
            break;
        case 115: // Down arrow
			game->player.y += DISK_SPEED;
            break;
        case 97: // Left arrow
			game->player.x -= DISK_SPEED;
            break;
        case 100: // Right arrow
			game->player.x += DISK_SPEED;
            break;
    }
	move_player(game);
    return 0;
}

int	key_release(int key, t_game *game)
{
	(void)game;
	printf("released: %i\n", key);
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

    draw_grid(&game);

	mlx_circle_filled(game.mlx, game.window, game.player.x, game.player.y, DISK_SIZE, 0x0000FF);
	// Set up keyboard events
	//mlx_hook(game.window, 3, 1L<<1, test_close, &game);
    //mlx_key_hook(game.window, key_press, (void *)&game);
	mlx_hook(game.window, 2, 1L<<0, key_press, (void *)&game);
	//mlx_hook(game.window, 3, 1L<<1, key_release, (void *)&game);
	mlx_loop(game.mlx);
    return 0;
}
