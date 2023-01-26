#include "cub3d.h"

int	valid_character(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.matrix[i])
	{
		j = 0;
		while (game->map.matrix[i][j])
		{
			if (ft_strchr("01 NSEW", game->map.matrix[i][j]) == 0)
			{
				ft_error("Invalid MapError : invalid character!\n");
				return (ERROR);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_file_extension(char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (ft_strcmp(file_name + (len - 4), ".cub")
		|| !file_name [len - 5]
		|| file_name[len - 5] == '/')
	{
		ft_error("wrong file extension\n");
		return (ERROR);
	}
	return (0);
}

char	*fetch_map_to_string(int fd)
{
	char	*line;
	char	*tmp;

	tmp = NULL;
	line = get_next_line(fd);
	while (line != NULL && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		if (line[0] == '\n')
		{
			free(line);
			free(tmp);
			return (NULL);
		}
		tmp = ft_strjoin(tmp, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (tmp);
}

void	fill_map_and_count_lines(t_game *game, char *tmp)
{
	int	i;
	int	size;

	i = 0;
	game->map.matrix = ft_split(tmp, '\n');
	while (game->map.matrix[i] != NULL)
	{
		size = ft_strlen(game->map.matrix[i]);
		if (size > game->map.width)
			game->map.width = size;
		game->map.height++;
		i++;
	}
	free(tmp);
}

int	check_around(t_game *game, int i, int j, int size)
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
