#include "cub3d.h"

int	init_game(t_game	*game, t_data *data)
{
	game->mlx = mlx_init();
    game->window = mlx_new_window(game->mlx, GAME_WIDTH * 2, GAME_HEIGHT * 2, "cub3D");
	game->player.line_length = 50;
	game->player.up = FALSE;
	game->player.down = FALSE;
	game->player.left = FALSE;
	game->player.right = FALSE;
	game->player.strafe_l = FALSE;
	game->player.strafe_r = FALSE;
    game->frame.img = NULL;
	game->minimap.frame.img = NULL;
	game->minimap.grid_size = 5;
	game->minimap.width = game->map.width * game->minimap.grid_size;
	game->minimap.height = game->map.height * game->minimap.grid_size;
	game->minimap_mask.img = mlx_xpm_file_to_image(game->mlx, "./textures/minimap_mask.xpm", &game->minimap_mask.width,  &game->minimap_mask.height);
	game->minimap_mask.addr = mlx_get_data_addr(game->minimap_mask.img, &game->minimap_mask.bits_per_pixel, &game->minimap_mask.line_length, &game->minimap_mask.endian);
  if (init_all_xpm(data, game) == ERROR)
    return (ERROR);
	int i=0;
	while (i < 9)
	{
		char *filename;
		filename = ft_strdup("./textures/rick/rick .xpm");
		filename[20] = i + '0';	
		game->textures.bonus[i].img = mlx_xpm_file_to_image(game->mlx, filename, &game->textures.bonus[i].width, &game->textures.bonus[i].height);
		game->textures.bonus[i].addr = mlx_get_data_addr(game->textures.bonus[i].img, &game->textures.bonus[i].bpp, 
				&game->textures.bonus[i].line_len, &game->textures.bonus[i].endian);
		free(filename);
		i++;
	}
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
	if (init_game(&game, &data) == ERROR)
    {
        free_data(&data);
        return (1);
    }
    free_data(&data);

	/////test bonus
	game.bonus = TRUE;
	game.frame_nb = 0;
	//////
	mlx_do_key_autorepeatoff(game.mlx);
	mlx_hook(game.window, 17, 0, quit_game, &game);
	mlx_hook(game.window, 2, 1L<<0, key_press, &game);
	mlx_hook(game.window, 3, 1L<<1, key_release, &game);
	mlx_loop_hook(game.mlx, game_routine, &game);
	mlx_loop(game.mlx);
    return 0;
}
