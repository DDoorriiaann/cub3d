#include "cub3d.h"

void	destroy_frames(t_game *game)
{
	if (game->frame.img)
	{
		mlx_destroy_image(game->mlx, game->frame.img);
		game->frame.img = NULL;
	}
	if (game->minimap.frame.img)
	{
		mlx_destroy_image(game->mlx, game->minimap.frame.img);
		game->minimap.frame.img = NULL;
	}
}

void	init_frames(t_game *game)
{
	game->frame.img = mlx_new_image(game->mlx, GAME_WIDTH, GAME_HEIGHT);
	game->frame.addr = mlx_get_data_addr(game->frame.img,
			&game->frame.bits_per_pixel, &game->frame.line_length,
			&game->frame.endian);
	game->minimap.frame.img = mlx_new_image(game->mlx,
			game->map.width * GRID_UNIT,
			game->map.height * GRID_UNIT);
	game->minimap.frame.addr = mlx_get_data_addr(game->minimap.frame.img,
			&game->minimap.frame.bits_per_pixel,
			&game->minimap.frame.line_length, &game->minimap.frame.endian);
}

int	game_routine(t_game *game)
{
	if (game->frame_nb > 72)
		game->frame_nb = 0;
	game->anim_frame_nb = game->frame_nb / 9;
	reset_player_movement(&game->player);
	get_player_input_directions(&game->player, game);
	init_frames(game);
	set_player_direction(&game->player);
	draw_floor_and_ceiling(game->frame, game->textures.ceiling_color,
		game->textures.floor_color);
	draw_minimap_background(game);
	draw_disc(game, (game->player.x / 128.0) * game->minimap.grid_size,
		(game->player.y / 128.0) * game->minimap.grid_size, 2);
	raycasting(game, game->player);
	draw_map(game);
	//zoom(game);
	draw_minimap(game, game->minimap.frame);
	mlx_put_image_to_window(game->mlx, game->window, game->frame.img, 0, 0);
	destroy_frames(game);
	game->frame_nb += 2;
	return (0);
}
