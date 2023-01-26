#include "cub3d.h"

static int	check_around(t_game *game, int i, int j, int size)
{
	if (j - 1 < 0 || ((game->map.matrix[i][j - 1] != '1')
		&& (game->map.matrix[i][j - 1] != '0')))
		return (ERROR);
	if (j + 1 >= size || ((game->map.matrix[i][j + 1] != '1')
		&& (game->map.matrix[i][j + 1] != '0')))
		return (ERROR);
	if (i - 1 < 0 || ((game->map.matrix[i - 1][j] != '1')
		&& (game->map.matrix[i - 1][j] != '0')))
		return (ERROR);
	if (i + 1 >= game->map.height || ((game->map.matrix[i + 1][j] != '1')
		&& (game->map.matrix[i + 1][j] != '0')))
		return (ERROR);
	return (0);
}

int	check_valid_map(t_game *game)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	while (game->map.matrix[i])
	{
		j = 0;
		size = ft_strlen(game->map.matrix[i]);
		while (j < size)
		{
			if (game->map.matrix[i][j] == '0')
			{
				if (check_around(game, i, j, size) == ERROR)
				{
					ft_error("Invalid MapError : the map is not closed\n");
					return (ERROR);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	player_exist(t_game *game)
{
	if (game->player.angle != -1)
		return (TRUE);
	return (FALSE);
}

int	fill_player_position(t_game *game)
{
	int	i;
	int	j;

	init_player(game);
	i = 0;
	while (game->map.matrix[i])
	{
		j = 0;
		while (game->map.matrix[i][j])
		{
			if (position_in_map(game, i, j) == ERROR)
				return (ERROR);
			j++;
		}
		i++;
	}
	return (0);
}
