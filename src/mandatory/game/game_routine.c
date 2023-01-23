#include "cub3d.h"

int	game_routine(t_game *game)
{
	static int frame = 0;
	//usleep(1000000/60);
	frame = frame + 1;
	game->player.dx = 0;
	game->player.dy = 0;
	if (game->player.up && !game->player.down)
	{
		//if (find_collision(game, game->player) == FALSE)
		//{
			game->player.dx = (int)(PLAYER_SPEED * cos(game->player.angle) * 20);
			game->player.dy = (int)(PLAYER_SPEED * sin(game->player.angle) * 20);
		//}
	}
	if (game->player.down && !game->player.up)
	{
		//if (find_collision(game, game->player) == FALSE)
		//{
			game->player.dx = (int)(PLAYER_SPEED * cos(game->player.angle) * 20) * -1;
			game->player.dy = (int)(PLAYER_SPEED * sin(game->player.angle) * 20) * -1;
		//}
	}
	if (game->player.left)
		game->player.angle = (game->player.angle - PLAYER_TURN_SPEED);
	if (game->player.right)
		game->player.angle = (game->player.angle + PLAYER_TURN_SPEED);
	if (!check_player_colision(game->map, (game->player.x + (game->player.dx * 10)) / GRID_UNIT, game->player.y / GRID_UNIT))
		game->player.x += game->player.dx;
	if (!check_player_colision(game->map,(game->player.x) / GRID_UNIT, (game->player.y  + (game->player.dy * 10)) / GRID_UNIT))
		game->player.y += game->player.dy;
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
	// if (frame % 20 == 0)
	// {
	// 	printf("angle: %f\n", game->player.angle * (180 / M_PI));
	// 	// printf("line end x: %f \nline end y : %f\n", game->player.x + (cos(game->player.angle) * game->player.line_length), game->player.y + (sin(game->player.angle) * game->player.line_length));
	// 	// printf("cos: %f\n", cos(game->player.angle));
	// 	// printf("sin: %f\n", sin(game->player.angle));
	// }
	draw_floor_and_ceiling(game->frame);
	
	//draw_grid(game);
	draw_disc(game, (game->player.x / 128.0) * game->minimap.grid_size, (game->player.y / 128.0) * game->minimap.grid_size, 2, 0xFF0000);
	
	raycasting(game, game->player);
	draw_map(game);
	
	// Put image to window
	//zoom(game);
	
	//draw_minimap(game, game->minimap.frame);
	
	mlx_put_image_to_window(game->mlx, game->window, game->frame.img, 0, 0);
	// sleep(1);
	if (game->frame.img)
	{
		mlx_destroy_image(game->mlx, game->frame.img);
		game->frame.img = NULL;
	}
	return (0);
}