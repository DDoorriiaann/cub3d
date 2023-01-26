#include "cub3d.h"

char	*replace_spaces_in_smaller_lines(t_game *game, int i, int j)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * game->map.width + 1);
	if (!tmp)
	{
		free_arr(game->map.matrix);
		return (NULL);
	}
	while (game->map.matrix[i][j])
	{
		if (game->map.matrix[i][j] == ' ')
			tmp[j] = '2';
		else
			tmp[j] = game->map.matrix[i][j];
		j++;
	}
	while (j < game->map.width)
		tmp[j++] = '2';
	tmp[j] = '\0';
	return (tmp);
}

void	replace_spaces_in_longer_lines(t_game *game, int i, int j)
{
	while (game->map.matrix[i][j])
	{
		if (game->map.matrix[i][j] == ' ')
			game->map.matrix[i][j] = '2';
		j++;
	}
}
