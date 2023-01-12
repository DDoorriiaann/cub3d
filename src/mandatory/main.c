#include "cub3d.h"




int main() 
{
    t_game	game;
	char	*map[]= {
		"1111111111",
		"1000011101",
		"1000010101",
		"1000011101",
		"1000000001",
		"1000000001",
		"1000010001",
		"1010000001",
		"1000000001",
		"1111111111"
	};

	// Initialize MinilibX
	game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, GAME_WIDTH + 1, GAME_HEIGHT + 1, "Minimap");

 	// Initialize disk position
    game.player.x = WINDOW_WIDTH / 2 + 25;
    game.player.y = WINDOW_HEIGHT / 2  + 30;
	game.player.angle = M_PI_2;
	game.player.line_length = 50;
	game.player.up = FALSE;
	game.player.down = FALSE;
	game.player.left = FALSE;
	game.player.right = FALSE;
    game.frame.img = NULL;
	game.map.matrix = map;
	game.map.map_height = 10;
	game.map.map_width = 10;

	// Set up keyboard events
	mlx_do_key_autorepeatoff(game.mlx);
	mlx_hook(game.window, 2, 1L<<0, key_press, &game);
	mlx_hook(game.window, 3, 1L<<1, key_release, &game);
	mlx_loop_hook(game.mlx, game_routine, &game);
	mlx_loop(game.mlx);
    return 0;
}
