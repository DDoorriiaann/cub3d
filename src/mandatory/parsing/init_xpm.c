#include "cub3d.h"

int	init_xpm_north(t_data *data, t_game *game)
{
	game->textures.north.addr = NULL;
	game->textures.north.img = mlx_xpm_file_to_image(game->mlx, data->NO,
			&game->textures.north.width, &game->textures.north.height);
	if (!game->textures.north.img)
	{
		ft_error("Invalid path : the path is not valid\n");
		return (ERROR);
	}
	game->textures.north.addr = mlx_get_data_addr(game->textures.north.img,
			&game->textures.north.bpp, &game->textures.north.line_len,
			&game->textures.north.endian);
	if (!game->textures.north.addr)
	{
		ft_error("Invalid path : the path is not valid\n");
		return (ERROR);
	}
	return (0);
}

int	init_xpm_south(t_data *data, t_game *game)
{
	game->textures.south.addr = NULL;
	game->textures.south.img = mlx_xpm_file_to_image(game->mlx, data->SO,
			&game->textures.south.width, &game->textures.south.height);
	if (!game->textures.south.img)
	{
		ft_error("Invalid path : the path is not valid\n");
		return (ERROR);
	}
	game->textures.south.addr = mlx_get_data_addr(game->textures.south.img,
			&game->textures.south.bpp, &game->textures.south.line_len,
			&game->textures.south.endian);
	if (!game->textures.south.addr)
	{
		ft_error("Invalid path : the path is not valid\n");
		return (ERROR);
	}
	return (0);
}

int	init_xpm_east(t_data *data, t_game *game)
{
	game->textures.east.addr = NULL;
	game->textures.east.img = mlx_xpm_file_to_image(game->mlx, data->EA,
			&game->textures.east.width, &game->textures.east.height);
	if (!game->textures.east.img)
	{
		ft_error("Invalid path : the path is not valid\n");
		return (ERROR);
	}
	game->textures.east.addr = mlx_get_data_addr(game->textures.east.img,
			&game->textures.east.bpp, &game->textures.east.line_len,
			&game->textures.east.endian);
	if (!game->textures.east.addr)
	{
		ft_error("Invalid path : the path is not valid\n");
		return (ERROR);
	}
	return (0);
}

int	init_xpm_west(t_data *data, t_game *game)
{
	game->textures.west.addr = NULL;
	game->textures.west.img = mlx_xpm_file_to_image(game->mlx, data->WE,
			&game->textures.west.width,
			&game->textures.west.height);
	if (!game->textures.west.img)
	{
		ft_error("Invalid path : the path is not valid\n");
		return (ERROR);
	}
	game->textures.west.addr = mlx_get_data_addr(game->textures.west.img,
			&game->textures.west.bpp, &game->textures.west.line_len,
			&game->textures.west.endian);
	if (!game->textures.west.addr)
	{
		ft_error("Invalid path : the path is not valid\n");
		return (ERROR);
	}
	return (0);
}

int	init_all_xpm(t_data *data, t_game *game)
{
	if (init_xpm_north(data, game) == ERROR)
		return (ERROR);
	if (init_xpm_south(data, game) == ERROR)
		return (ERROR);
	if (init_xpm_east(data, game) == ERROR)
		return (ERROR);
	if (init_xpm_west(data, game) == ERROR)
		return (ERROR);
	game->minimap_mask.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/minimap_mask.xpm", &game->minimap_mask.width,
			&game->minimap_mask.height);
	game->minimap_mask.addr = mlx_get_data_addr(game->minimap_mask.img,
			&game->minimap_mask.bits_per_pixel, &game->minimap_mask.line_length,
			&game->minimap_mask.endian);
	return (0);
}