#include "cub3d.h"

void	draw_minimap_background(t_game *game)
{
	int			x;
	int			y;
	int			cell_nb = 0;
	t_minimap	minimap; 
	
	minimap = game->minimap;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			cell_nb++;
			draw_square(game, x * minimap.grid_size , y * minimap.grid_size, 0x000000);
			// else
			// 	draw_square(game, x * minimap.grid_size, y * minimap.grid_size, 0x000000);
			x++;
		}
		y++;
	}
}