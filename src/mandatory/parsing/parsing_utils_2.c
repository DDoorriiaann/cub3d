#include "cub3d.h"

int    check_is_valid_color(int color)
{
    if (color < 0 || color > 255)
    {
        ft_error("The color must be between 0 and 255\n");
        return (ERROR);
    }
    return (0);
}

char	*save_path(t_data *data, char *line)
{

    int i;
    int j;
    int len;
    char *tmp;

    i = 2;
    j = 0;
    check_empty_string(data, line);
    while (line[i] == ' ' || line[i] == '\t'
           || line[i] == '\r' || line[i] == '\v' || line[i] == '\f')
        i++;
    len = ft_strlen_path(i, line);
    tmp = malloc(sizeof(char *) * len + 1);
    if (!tmp)
    {
        free(line);
        return (NULL);
    }
    while (line[i])
    {
        tmp[j] = line[i];
        i++;
        j++;
    }
    tmp[j] = '\0';
    free(line);
    line = NULL;
    return (tmp);
}
int get_hex_color(int r, int g, int b)
{
    int color;

    color = (r << 16) | (g << 8) | b;
    return (color);
}

int fill_spaces_map(t_game *game)
{
    int i;
    int j;
    int len;
    char *tmp;

    i = 0;
    len = 0;
    while (i < game->map.height)
    {
        j = 0;
        len = ft_strlen(game->map.matrix[i]);
        if (len < game->map.width)
        {
            tmp = malloc(sizeof(char) * game->map.width + 1);
            if (!tmp)
            {
                free_arr(game->map.matrix);
                return (ERROR);
            }
            while(game->map.matrix[i][j])
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
            free(game->map.matrix[i]);
            game->map.matrix[i] = tmp;
            tmp = NULL;
        }
        else
        {
            while(game->map.matrix[i][j])
            {
                if (game->map.matrix[i][j] == ' ')
                    game->map.matrix[i][j] = '2';
                j++;
            }
        }
        printf("map = %s\n", game->map.matrix[i]);
        i++;
    }
    return (0);
}