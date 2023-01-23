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

int	read_fd(t_data *data,t_game *game,  int fd)
{
    char    *tmp;

    if (check_map_description(data, fd))
    {
        ft_error("Invalid information\n");
        return (1);
    }
	check_floor(data);
    check_ceiling(data);
    tmp = fetch_map_to_string(fd);
    if (tmp == NULL)
        return (1);
    fill_map_and_count_lines(game, tmp);
    if (valid_character(game))
        return (1);
    if (fill_player_position(game))
        return (1);
    if(!player_exist(game))
    {
        ft_error("Invalid MapError : the map must contain at least one player");
        return (1);
    }
    check_valid_map(game);
    //check_images(data);
	return (0);
}