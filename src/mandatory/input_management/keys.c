#include "cub3d.h"

int key_press(int key, t_game *game) 
{
	if (key == 119)
		game->player.up = TRUE;
	else if (key == 115)
		game->player.down = TRUE;
	else if (key == 97)
		game->player.left = TRUE;
	else if (key == 100)
		game->player.right = TRUE;
	else if (key == 65307)
		quit_game(game);

	return 0;
}

int	key_release(int key, t_game *game)
{
	if (key == 119)
		game->player.up = FALSE;
	else if (key == 115)
		game->player.down = FALSE;
	else if (key == 97)
		game->player.left = FALSE;
	else if (key == 100)
		game->player.right = FALSE;

	return 0;
}