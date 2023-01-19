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
		"101000100000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000001",
		"100000000000000000000010000000000000000000000000001",
		"100001000000000000000000000000000000100000000000001",
		"101000100000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000001",
		"100000000000000000000010000000000000000000000000001",
		"100001000000000000000000000000000000100000000000001",
		"101000100000000000000000000000000000000000000000001",
		"100000000000000000000000000000000000000000000000001",
		"111111111111111111111111111111111111111111111111111"
	};

	// Initialize MinilibX
	game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, GAME_WIDTH, GAME_HEIGHT, "cub3D");

 	// Initialize disk position
    // game.player.x = MINIMAP_WIDTH / 2 + 12;
    // game.player.y = MINIMAP_HEIGHT/ 2  + 15;
	game.player.x = 280;
	game.player.y = 280;
	game.player.angle = M_PI / 2;
	game.player.line_length = 50;
	game.player.up = FALSE;
	game.player.down = FALSE;
	game.player.left = FALSE;
	game.player.right = FALSE;
    game.frame.img = NULL;
	game.map.matrix = map;
	game.map.height = 20;
	game.map.width = 51;
	game.textures.north.img = mlx_xpm_file_to_image(game.mlx, "./textures/wall1.xpm", &game.textures.north.width,  &game.textures.north.height);
	game.textures.north.addr = mlx_get_data_addr(game.textures.north.img, &game.textures.north.bpp, &game.textures.north.line_len, &game.textures.north.endian);
	game.textures.south.img = mlx_xpm_file_to_image(game.mlx, "./textures/wall2.xpm", &game.textures.south.width,  &game.textures.south.height);
	game.textures.south.addr = mlx_get_data_addr(game.textures.south.img, &game.textures.south.bpp, &game.textures.south.line_len, &game.textures.south.endian);
	game.textures.west.img = mlx_xpm_file_to_image(game.mlx, "./textures/wall3.xpm", &game.textures.west.width,  &game.textures.west.height);
	game.textures.west.addr = mlx_get_data_addr(game.textures.west.img, &game.textures.west.bpp, &game.textures.west.line_len, &game.textures.west.endian);
	game.textures.east.img = mlx_xpm_file_to_image(game.mlx, "./textures/wall4.xpm", &game.textures.east.width,  &game.textures.east.height);
	game.textures.east.addr = mlx_get_data_addr(game.textures.east.img, &game.textures.east.bpp, &game.textures.east.line_len, &game.textures.east.endian);
	//printf("texture width : %d texture height: %d\n", game.textures.north_width, game.textures.north_height);
	// Set up keyboard events
	mlx_do_key_autorepeatoff(game.mlx);
	mlx_hook(game.window, 2, 1L<<0, key_press, &game);
	mlx_hook(game.window, 3, 1L<<1, key_release, &game);
	mlx_loop_hook(game.mlx, game_routine, &game);
	mlx_loop(game.mlx);
    return 0;
}
