#include "cub3d.h"




int main() 
{
    t_game	game;
	char	*map[]= {
		"111111111111111111111111111111111111111111111111111",
		"100001110000000000000000000000000000000000000000001",
		"100001010000000000000000000000000000000000000000001",
		"100001110000000000000100000000000000000000000000001",
		"100000000000000000000000000000000000000000000000001",
		"100000000000000000000010000000000000000000000000001",
		"100001000000000000000000000000000000100000000000001",
		"101000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000001",
		"111111111111111111111111111111111111111111111111111"
	};

	// Initialize MinilibX
	game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, GAME_WIDTH * 2, GAME_HEIGHT * 2, "cub3D");

 	// Initialize disk position
    game.player.x = MINIMAP_WIDTH / 2 + 12;
    game.player.y = MINIMAP_HEIGHT/ 2  + 15;
	game.player.angle = M_PI /2 - M_PI / 4;
	game.player.line_length = 50;
	game.player.up = FALSE;
	game.player.down = FALSE;
	game.player.left = FALSE;
	game.player.right = FALSE;
    game.frame.img = NULL;
	game.map.matrix = map;
	game.map.height = 10;
	game.map.width = 51;

	// Set up keyboard events
	mlx_do_key_autorepeatoff(game.mlx);
	mlx_hook(game.window, 2, 1L<<0, key_press, &game);
	mlx_hook(game.window, 3, 1L<<1, key_release, &game);
	mlx_loop_hook(game.mlx, game_routine, &game);
	mlx_loop(game.mlx);
    return 0;
}
