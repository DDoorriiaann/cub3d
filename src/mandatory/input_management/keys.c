#include "cub3d.h"

int	key_press(int key, t_game *game)
{
	if (key == 65362 || key == 119)
		game->player.up = TRUE;
	else if (key == 65364 || key == 115)
		game->player.down = TRUE;
	else if (key == 65361 || key == 113)
		game->player.left = TRUE;
	else if (key == 65363 || key == 101)
		game->player.right = TRUE;
	else if (key == 97)
		game->player.strafe_l = TRUE;
	else if (key == 100)
		game->player.strafe_r = TRUE;
	else if (key == 65307)
		quit_game(game);
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == 65362 || key == 119)
		game->player.up = FALSE;
	else if (key == 65364 || key == 115)
		game->player.down = FALSE;
	else if (key == 65361 || key == 113)
		game->player.left = FALSE;
	else if (key == 65363 || key == 101)
		game->player.right = FALSE;
	else if (key == 97)
		game->player.strafe_l = FALSE;
	else if (key == 100)
		game->player.strafe_r = FALSE;
	return (0);
}
