#include "cub3d.h"

void	north_position(t_game *game, int i, int j)
{
	game->player.angle = 3 * (M_PI / 2);
	game->player.x = (j * 128) + 64;
	game->player.y = (i * 128) + 64;
	game->map.matrix[i][j] = '0';
}

void	south_position(t_game *game, int i, int j)
{
	game->player.angle = M_PI / 2;
	game->player.x = (j * 128) + 64;
	game->player.y = (i * 128) + 64;
	game->map.matrix[i][j] = '0';
}

void	east_position(t_game *game, int i, int j)
{
	game->player.angle = 0;
	game->player.x = (j * 128) + 64;
	game->player.y = (i * 128) + 64;
	game->map.matrix[i][j] = '0';
}

void	west_position(t_game *game, int i, int j)
{
	game->player.angle = M_PI;
	game->player.x = (j * 128) + 64;
	game->player.y = (i * 128) + 64;
	game->map.matrix[i][j] = '0';
}

int	position_in_map(t_game *game, int i, int j)
{
	if (game->map.matrix[i][j] == 'N' && player_exist(game) == FALSE)
		north_position(game, i, j);
	else if (game->map.matrix[i][j] == 'S'
			&& player_exist(game) == FALSE)
		south_position(game, i, j);
	else if (game->map.matrix[i][j] == 'E'
			&& player_exist(game) == FALSE)
		east_position(game, i, j);
	else if (game->map.matrix[i][j] == 'W'
			&& player_exist(game) == FALSE)
		west_position(game, i, j);
	else if (game->map.matrix[i][j] != '0'
			&& game->map.matrix[i][j] != '1'
			&& game->map.matrix[i][j] != ' ')
	{
		ft_error("Invalid MapError : Too many players\n");
		return (ERROR);
	}
	return (0);
}
