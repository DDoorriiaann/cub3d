#include "cub3d.h"

void	init_data(t_data *data, t_game *game)
{
	data->NO = NULL;
	data->SO = NULL;
	data->WE = NULL;
	data->EA = NULL;
	data->F = NULL;
	data->C = NULL;
	data->count = 0;
	game->map.matrix = NULL;
	game->minimap_mask.img = NULL;
	game->map.width = 0;
	game->map.height = 0;
}

void	init_player(t_game *game)
{
	game->player.angle = -1;
}
