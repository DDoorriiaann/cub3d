#include "cub3d.h"

void	free_data(t_data *data)
{
	if (data->NO)
		free(data->NO);
	if (data->SO)
		free(data->SO);
	if (data->EA)
		free(data->EA);
	if (data->WE)
		free(data->WE);
	if (data->F)
		free(data->F);
	if (data->C)
		free(data->C);
}

void	free_xpm(t_game *game, t_textures *textures)
{
	if (textures->north.img)
		mlx_destroy_image(game->mlx, textures->north.img);
	if (textures->south.img)
		mlx_destroy_image(game->mlx, textures->south.img);
	if (textures->east.img)
		mlx_destroy_image(game->mlx, textures->east.img);
	if (textures->west.img)
		mlx_destroy_image(game->mlx, textures->west.img);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
