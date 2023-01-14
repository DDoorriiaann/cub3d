#include "cub3d.h"

int	game_routine(t_game *game)
{
	static int frame = 0;
	//usleep(1000000/60);
	frame = frame + 1;
	if (game->player.up)
	{
		if (find_collision(game, game->player) == FALSE)
		{
			game->player.x -= PLAYER_SPEED * cos(game->player.angle);
			game->player.y -= PLAYER_SPEED * sin(game->player.angle);
		}
	}
	if (game->player.down)
	{
		if (find_collision(game, game->player) == FALSE)
		{
			game->player.x += PLAYER_SPEED * cos(game->player.angle);
			game->player.y += PLAYER_SPEED * sin(game->player.angle);
		}
	}
	if (game->player.left)
		game->player.angle = (game->player.angle - PLAYER_TURN_SPEED);
	if (game->player.right)
		game->player.angle = (game->player.angle + PLAYER_TURN_SPEED);

	// Create image and get address
	game->frame.img = mlx_new_image(game->mlx, GAME_WIDTH, GAME_HEIGHT);
	game->frame.addr = mlx_get_data_addr(game->frame.img, &game->frame.bits_per_pixel, &game->frame.line_length, &game->frame.endian);
	
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
//	if (frame % 20 == 0)
//	{
//		printf("angle: %f\n", game->player.angle);
//		printf("line end x: %f \nline end y : %f\n", game->player.x + (cos(game->player.angle) * game->player.line_length), game->player.y + (sin(game->player.angle) * game->player.line_length));
//		printf("cos: %f\n", cos(game->player.angle));
//		printf("sin: %f\n", sin(game->player.angle));
//	}
	// Draw grid
	
	draw_map(game);
	draw_grid(game);
	// Draw disk
	//draw_target(game, game->player, game->player.x - (cos(game->player.angle) * game->player.line_length), game->player.y - (sin(game->player.angle) * game->player.line_length));
	raycasting(game, game->player);
	mlx_circle_filled(game, game->player.x, game->player.y, PLAYER_SIZE, 0x0000FF);
	
	// Put image to window
	mlx_put_image_to_window(game->mlx, game->window, game->frame.img, 0, 0);
	if (game->frame.img)
	{
		mlx_destroy_image(game->mlx, game->frame.img);
		game->frame.img = NULL;
	}
	return (0);
}