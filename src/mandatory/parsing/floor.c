#include "cub3d.h"

static int	check_number(char **tmp)
{
	if ((check_is_number(tmp[0]) == ERROR) || (check_is_number(tmp[1]) == ERROR)
		|| (check_is_number(tmp[2]) == ERROR))
	{
		free_arr(tmp);
		return (ERROR);
	}
	return (0);
}

static int	check_color(char **tmp, int r, int g, int b)
{
	if ((check_is_valid_color(r) == ERROR) || (check_is_valid_color(g) == ERROR)
		|| (check_is_valid_color(b) == ERROR))
	{
		free_arr(tmp);
		return (ERROR);
	}
	return (0);
}

static int	check_coma(t_data *data)
{
	if (ft_number_comma(data->F) != 2)
	{
		ft_error("there is not the right number of commas\n");
		return (ERROR);
	}
	return (0);
}

int	check_floor(t_data *data, t_textures *textures)
{
	int		r;
	int		g;
	int		b;
	char	**tmp;

	if (check_coma(data) == ERROR)
		return (ERROR);
	tmp = ft_split(data->F, ',');
	if (! tmp || !tmp[0] || !tmp[1] || !tmp[2])
	{
		free_arr(tmp);
		return (1);
	}
	if (check_number(tmp) == ERROR)
		return (ERROR);
	r = ft_atoi(tmp[0]);
	g = ft_atoi(tmp[1]);
	b = ft_atoi(tmp[2]);
	if (check_color(tmp, r, g, b) == ERROR)
		return (1);
	free_arr(tmp);
	textures->floor_color = get_hex_color(r, g, b);
	return (0);
}
