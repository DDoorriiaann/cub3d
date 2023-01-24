#include "cub3d.h"

void	draw_minimap_background(t_game *game)
{
	int			x;
	int			y;
	int			cell_nb;
	t_minimap	minimap;

	minimap = game->minimap;
	cell_nb = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			cell_nb++;
			draw_square(game, x * minimap.grid_size,
				y * minimap.grid_size, 0x000000);
			x++;
		}
		y++;
	}
}

void draw_minimap(t_game *game, t_frame minimap)
{
	t_minimap_draw	data;

	data.y = 0;
	data.player_x = (int)((game->player.x / 128.0) * game->minimap.grid_size);
	data.player_y = (int)((game->player.y / 128.0) * game->minimap.grid_size);
	data.src_y = data.player_y - 75;
	while (data.y < 150)
	{
		data.src_x = data.player_x - 75;
		data.x = 0;
		while (data.x < 150)
		{
			if (get_pixel(game->minimap_mask, data.x, data.y) != 0x12ff00)
			{
				if (data.src_x > 0 && data.src_y > 0
					&& data.src_x < game->minimap.width
					&& data.src_y < game->minimap.height)
					my_mlx_pixel_put(&game->frame, data.x + 625,
						data.y + 25,
						get_pixel(minimap, data.src_x, data.src_y));
				else
					my_mlx_pixel_put(&game->frame, data.x + 625,
						data.y + 25, 0x000000);
			}
			data.x++;
			data.src_x++;
		}
		data.y++;
		data.src_y++;
	}
}
