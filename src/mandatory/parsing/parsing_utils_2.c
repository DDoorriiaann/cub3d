#include "cub3d.h"

int	check_is_valid_color(int color)
{
	if (color < 0 || color > 255)
	{
		ft_error("The color must be between 0 and 255\n");
		return (ERROR);
	}
	return (0);
}

static char	*copy_path(char *line, int i, int j, int len)
{
	char	*tmp;

	tmp = malloc(sizeof(char *) * len + 1);
	if (!tmp)
	{
		free(line);
		return (NULL);
	}
	while (line[i] && line[i] != '\n')
	{
		tmp[j] = line[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*save_path(t_data *data, char *line)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	i = 2;
	j = 0;
	check_empty_string(data, line);
	while (line[i] == ' ' || line[i] == '\t'
		|| line[i] == '\r' || line[i] == '\v' || line[i] == '\f')
		i++;
	len = ft_strlen_path(i, line);
	tmp = copy_path(line, i, j, len);
	if (tmp == NULL)
		return (NULL);
	free(line);
	line = NULL;
	return (tmp);
}

int	get_hex_color(int r, int g, int b)
{
	int	color;

	color = (r << 16) | (g << 8) | b;
	return (color);
}

int	fill_spaces_map(t_game *game)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	i = 0;
	len = 0;
	while (i < game->map.height)
	{
		j = 0;
		len = ft_strlen(game->map.matrix[i]);
		if (len < game->map.width)
		{
			tmp = replace_spaces_in_smaller_lines(game, i, j);
			if (tmp == NULL)
				return (ERROR);
			free(game->map.matrix[i]);
			game->map.matrix[i] = tmp;
		}
		else
			replace_spaces_in_longer_lines(game, i, j);
		i++;
	}
	return (0);
}
