#include "cub3d.h"

int	init_game(t_game	*game, t_data *data)
{
	(void)data;
	game->mlx = mlx_init();
    game->window = mlx_new_window(game->mlx, GAME_WIDTH * 2, GAME_HEIGHT * 2, "cub3D");
	game->player.line_length = 50;
	game->player.up = FALSE;
	game->player.down = FALSE;
	game->player.left = FALSE;
	game->player.right = FALSE;
    game->frame.img = NULL;
	game->minimap.frame.img = NULL;
	game->minimap.grid_size = 5;
	game->minimap.width = game->map.width * game->minimap.grid_size;
	game->minimap.height = game->map.height * game->minimap.grid_size;
	game->minimap_mask.img = mlx_xpm_file_to_image(game->mlx, "./textures/minimap_mask.xpm", &game->minimap_mask.width,  &game->minimap_mask.height);
	game->minimap_mask.addr = mlx_get_data_addr(game->minimap_mask.img, &game->minimap_mask.bits_per_pixel, &game->minimap_mask.line_length, &game->minimap_mask.endian);
	printf("north path: '%s'\n", data->NO );
	game->textures.north.img = mlx_xpm_file_to_image(game->mlx, data->NO, &game->textures.north.width,  &game->textures.north.height);
	game->textures.north.addr = mlx_get_data_addr(game->textures.north.img, &game->textures.north.bpp, &game->textures.north.line_len, &game->textures.north.endian);
	game->textures.south.img = mlx_xpm_file_to_image(game->mlx, data->SO, &game->textures.south.width,  &game->textures.south.height);
	game->textures.south.addr = mlx_get_data_addr(game->textures.south.img, &game->textures.south.bpp, &game->textures.south.line_len, &game->textures.south.endian);
	game->textures.west.img = mlx_xpm_file_to_image(game->mlx, data->WE, &game->textures.west.width,  &game->textures.west.height);
	game->textures.west.addr = mlx_get_data_addr(game->textures.west.img, &game->textures.west.bpp, &game->textures.west.line_len, &game->textures.west.endian);
	game->textures.east.img = mlx_xpm_file_to_image(game->mlx, data->EA, &game->textures.east.width,  &game->textures.east.height);
	game->textures.east.addr = mlx_get_data_addr(game->textures.east.img, &game->textures.east.bpp, &game->textures.east.line_len, &game->textures.east.endian);
	return 0;
}

int main(int argc, char **argv) 
{

	t_data	data;
	t_game  game;
	int		fd;

	if (argc != 2)
	{
		ft_error("You must enter two parameters\n");
		return (1);
	}
	if (check_file_extension(argv[1]))
		return (1);
	init_data(&data, &game);
	fd = open_fd(argv[1]);
	if  (read_fd(&data, &game, fd, &game.textures) == ERROR)
    {
        free_data(&data);
        return (1);
    }
	init_game(&game, &data);
  free_data(&data);
	mlx_do_key_autorepeatoff(game.mlx);
	mlx_hook(game.window, 2, 1L<<0, key_press, &game);
	mlx_hook(game.window, 3, 1L<<1, key_release, &game);
	mlx_loop_hook(game.mlx, game_routine, &game);
	mlx_loop(game.mlx);
    return 0;
}
