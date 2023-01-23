#include "cub3d.h"

void    check_is_valid_color(int color)
{
    if (color < 0 || color > 255)
        ft_error("The color must be between 0 and 255\n");
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