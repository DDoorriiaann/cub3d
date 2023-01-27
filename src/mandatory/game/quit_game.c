#include "cub3d.h"

int	quit_game(t_game *game)
{
	if (game->mlx)
	{
		mlx_do_key_autorepeaton(game->mlx);
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		destroy_frames(game);
		if (game->minimap_mask.img)
			mlx_destroy_image(game->mlx, game->minimap_mask.img);
		free_xpm(game, &game->textures);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map.matrix)
		free_arr(game->map.matrix);
	exit(0);
	return (0);
}
