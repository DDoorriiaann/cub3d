#include "cub3d.h"

int    check_ceiling(t_data *data, t_textures *textures)
{
    int r;
    int g;
    int b;
    char **tmp;

    if (ft_number_comma(data->C) != 2)
    {
        ft_error("there is not the right number of commas\n");
        return (ERROR);
    }
    tmp = ft_split(data->C, ',');
    if (!tmp)
    {
        free_arr(tmp);
        return (ERROR);
    }
    if (!tmp[0] || !tmp[1] || !tmp[2])
    {
        free_arr(tmp);
        return (ERROR);
    }
    if ((check_is_number(tmp[0]) == ERROR) || (check_is_number(tmp[1]) == ERROR) || (check_is_number(tmp[2]) == ERROR))
    {
        free_arr(tmp);
        return (ERROR);
    }
    r = ft_atoi(tmp[0]);
    g = ft_atoi(tmp[1]);
    b = ft_atoi(tmp[2]);
    if ((check_is_valid_color(r) == ERROR) || (check_is_valid_color(g) == ERROR) || (check_is_valid_color(b) == ERROR))
    {
        free_arr(tmp);
        return (ERROR);
    }
    free_arr(tmp);
    textures->ceiling_color = get_hex_color(r, g, b);
    return (0);
}