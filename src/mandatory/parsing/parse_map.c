#include "cub3d.h"

int valid_character(t_game *game)
{
	int	i;
    int j;

	i = 0;
	while (game->map.matrix[i])
	{
        j = 0;
        while (game->map.matrix[i][j])
        {
            if (ft_strchr("01 NSEW", game->map.matrix[i][j]) == 0)
            {
                ft_error("Invalid MapError : invalid character!");
                return (1);
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
		return (1);
	}
	return (0);
}

char    *fetch_map_to_string(int fd)
{
    char	*line;
    char    *tmp;

    tmp = NULL;
    line = get_next_line(fd);
    while (line != NULL && line[0] == '\n')
    {
        free(line);
        line = get_next_line(fd);
    }
    while (line != NULL )
    {
        if ( line[0] == '\n')
        {
            ft_error("Invalid MapError : the map contains empty lines\n");
            return (NULL);
        }
        tmp = ft_strjoin(tmp, line);
        free(line);
        line = get_next_line(fd);
    }
    return (tmp);
}

void  fill_map_and_count_lines(t_game *game, char *tmp)
{
    int i;
    int size;

    i = 0;
    game->map.matrix = ft_split(tmp, '\n');
    while ( game->map.matrix[i] != NULL)
    {
        printf("map =  %s\n", game->map.matrix[i]);
        size = ft_strlen(game->map.matrix[i]);
        if (size > game->map.width)
            game->map.width = size;
        game->map.height++;
        i++;
    }
    printf("map_width = %i\n", game->map.width);
    printf("map_height = %i\n", game->map.height);
}

int    check_around(t_game *game, int i, int j, int size)
{
    if (j - 1 < 0 || ((game->map.matrix[i][j - 1] != '1') && (game->map.matrix[i][j - 1] != '0')))
        return (1);
    if (j + 1 >= size || ((game->map.matrix[i][j + 1] != '1') && (game->map.matrix[i][j + 1] != '0')))
        return (1);
    if (i - 1 < 0 || ((game->map.matrix[i - 1][j] != '1') && (game->map.matrix[i - 1][j] != '0')))
        return (1);
    if (i + 1 >= game->map.height || ((game->map.matrix[i + 1][j] != '1') && (game->map.matrix[i + 1][j] != '0')))
        return (1);
    return (0);
}

int    check_valid_map(t_game *game)
{
    int i;
    int j;
    int size;

    i = 0;
    while (game->map.matrix[i])
    {
        j = 0;
        size = ft_strlen(game->map.matrix[i]);
        while (j < size)
        {
            if (game->map.matrix[i][j] == '0')
                if (check_around(game, i, j, size))
                {
                    ft_error("Invalid MapError : the map is not closed\n");
                    return (1);
                }
            j++;
        }
        i++;
    }
    return (0);
}

int    player_exist(t_game *game)
{
    if (game->player.angle != -1)
        return (TRUE);
    return (FALSE);
}

int fill_player_position(t_game *game)
{
    int	i;
    int j;

    init_player(game);
    i = 0;
    while (game->map.matrix[i])
    {
        j = 0;
        while (game->map.matrix[i][j])
        {
            if (game->map.matrix[i][j] == 'N' && player_exist(game) == FALSE)
            {
                game->player.angle = M_PI / 2;
                game->map.matrix[i][j] = '0';
            }
            else if (game->map.matrix[i][j] == 'S' && player_exist(game) == FALSE)
            {
                game->player.angle = 3 * (M_PI / 2);
                game->map.matrix[i][j] = '0';
            }
            else if (game->map.matrix[i][j] == 'E' && player_exist(game) == FALSE)
            {
                game->player.angle = 0;
                game->map.matrix[i][j] = '0';
            }
            else if (game->map.matrix[i][j] == 'W' && player_exist(game) == FALSE)
            {
                game->player.angle = M_PI;
                game->map.matrix[i][j] = '0';
            }
            else if (game->map.matrix[i][j] != '0' && game->map.matrix[i][j] != '1' && game->map.matrix[i][j] != ' ')
            {
                ft_error("Invalid MapError : Too many players\n");
                return (1);
            }
            j++;
        }
        i++;
    }
    printf("angle = %f\n", game->player.angle);
    return (0);
}