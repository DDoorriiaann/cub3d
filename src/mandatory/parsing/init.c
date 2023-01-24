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
    game->map.width = 0;
    game->map.height = 0;
}

void    init_player(t_game *game)
{
    game->player.angle = -1;
}

int	open_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("failed to open fd\n");
	return (fd);
}

int	read_fd(t_data *data,t_game *game, int fd, t_textures *textures)
{
    char    *tmp;

    if (check_map_description(data, fd))
    {
        ft_error("Invalid information\n");
        return (ERROR);
    }
	if (check_floor(data, textures) == ERROR)
        return (ERROR);
    if (check_ceiling(data, textures) == ERROR)
        return(ERROR);
    tmp = fetch_map_to_string(fd);
    if (tmp == NULL)
        return (ERROR);
    fill_map_and_count_lines(game, tmp);
    if (valid_character(game))
        return (ERROR);
    if (fill_player_position(game))
        return (ERROR);
    if (check_valid_map(game) == ERROR)
        return (ERROR);
    fill_spaces_map(game);
    if(!player_exist(game))
    {
        ft_error("Invalid MapError : the map must contain at least one player");
        return (ERROR);
    }
    return (0);
}