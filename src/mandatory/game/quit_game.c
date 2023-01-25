#include "cub3d.h"

int	quit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	destroy_frames(game);
	mlx_do_key_autorepeaton(game->mlx);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
