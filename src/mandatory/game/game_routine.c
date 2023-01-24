#include "cub3d.h"

void	reset_player_movement(t_player *player)
{
	player->dx = 0;
	player->dy = 0;
}

void	get_player_input_directions(t_player *player, t_game *game)
{
	if (player->up && !player->down)
	{
		player->dx = (int)(PLAYER_SPEED * cos(player->angle) * 20);
		player->dy = (int)(PLAYER_SPEED * sin(player->angle) * 20);
	}
	if (player->down && !player->up)
	{
		player->dx = (int)-(PLAYER_SPEED * cos(player->angle) * 20);
		player->dy = (int)-(PLAYER_SPEED * sin(player->angle) * 20);
	}
	if (player->left)
		player->angle = (player->angle - PLAYER_TURN_SPEED);
	if (player->right)
		player->angle = (player->angle + PLAYER_TURN_SPEED);
	if (!check_player_colision(game->map, (game->player.x + (game->player.dx * 10))
			/ GRID_UNIT, game->player.y / GRID_UNIT))
		game->player.x += game->player.dx;
	if (!check_player_colision(game->map,(game->player.x) / GRID_UNIT, (game->player.y  + (game->player.dy * 10)) / GRID_UNIT))
		game->player.y += game->player.dy;
}

int	game_routine(t_game *game)
{
	reset_player_movement(&game->player);
	get_player_input_directions(&game->player, game);
	// Create image and get address
	game->frame.img = mlx_new_image(game->mlx, GAME_WIDTH, GAME_HEIGHT);
	game->frame.addr = mlx_get_data_addr(game->frame.img, &game->frame.bits_per_pixel, &game->frame.line_length, &game->frame.endian);
	game->minimap.frame.img = mlx_new_image(game->mlx, game->map.width * GRID_UNIT, game->map.height * GRID_UNIT);
	game->minimap.frame.addr = mlx_get_data_addr(game->minimap.frame.img, &game->minimap.frame.bits_per_pixel, &game->minimap.frame.line_length, &game->minimap.frame.endian);
	if (game->player.angle > 2 * M_PI)
		game->player.angle -= 2 * M_PI;
	else if (game->player.angle < 0)
		game->player.angle += 2 * M_PI;
	if (cos(game->player.angle >= 0))
		game->player.x_dir = -1;
	else
		game->player.x_dir = 1;
	if (sin(game->player.angle >= 0))
		game->player.y_dir = 1;
	else
		game->player.y_dir = -1;
	draw_floor_and_ceiling(game->frame);
	draw_minimap_background(game);
	draw_disc(game, (game->player.x / 128.0) * game->minimap.grid_size,
			(game->player.y / 128.0) * game->minimap.grid_size, 2);
	raycasting(game, game->player);
	draw_map(game);
	zoom(game);
	draw_minimap(game, game->minimap.frame);
	mlx_put_image_to_window(game->mlx, game->window, game->frame.img, 0, 0);
	if (game->frame.img)
	{
		mlx_destroy_image(game->mlx, game->frame.img);
		game->frame.img = NULL;
	}
	return (0);
}
