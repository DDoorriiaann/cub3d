#include "cub3d.h"

int	open_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("failed to open fd\n");
	return (fd);
}

static int	check_player(t_game *game)
{
	if (!player_exist(game))
	{
		ft_error("Invalid MapError : map must contain at least one player\n");
		return (ERROR);
	}
	return (0);
}

static int	check_description(t_data *data, int fd)
{
	if (check_map_description(data, fd))
	{
		ft_error("Invalid information\n");
		return (ERROR);
	}
	return (0);
}

int	read_fd(t_data *data, t_game *game, int fd, t_textures *textures)
{
	char	*tmp;

	if (check_description(data, fd) == ERROR)
		return (ERROR);
	if (check_floor(data, textures) == ERROR)
		return (ERROR);
	if (check_ceiling(data, textures) == ERROR)
		return (ERROR);
	tmp = fetch_map_to_string(fd);
	if (tmp == NULL)
	{
		ft_error("Invalid map : Map Error !\n");
		return (ERROR);
	}
	fill_map_and_count_lines(game, tmp);
	if (valid_character(game))
		return (ERROR);
	if (fill_player_position(game))
		return (ERROR);
	if (check_valid_map(game) == ERROR)
		return (ERROR);
	fill_spaces_map(game);
	if (check_player(game) == ERROR)
		return (ERROR);
	return (0);
}
