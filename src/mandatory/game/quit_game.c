#include "cub3d.h"

void	quit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	if (game->frame.img)
		mlx_destroy_image(game->mlx, game->frame.img);
	mlx_do_key_autorepeaton(game->mlx);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}