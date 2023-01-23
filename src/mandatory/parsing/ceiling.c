#include "cub3d.h"

void    check_ceiling(t_data *data)
{
    int r;
    int g;
    int b;
    char **tmp;

    if (ft_number_comma(data->C) != 2)
        ft_error("Too many comma\n");
    tmp = ft_split(data->C, ',');
    if (!tmp)
        return ; // TODO free and leave
    if (!(tmp[0] && tmp[1] && tmp[2]))
        return ; // TODO free and leave
    check_is_number(tmp[0]);
    check_is_number(tmp[1]);
    check_is_number(tmp[2]);
    r = ft_atoi(tmp[0]);
    g = ft_atoi(tmp[1]);
    b = ft_atoi(tmp[2]);
    check_is_valid_color(r);
    check_is_valid_color(g);
    check_is_valid_color(b);
}