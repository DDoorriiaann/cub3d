#include "cub3d.h"

int	get_pixel(t_frame frame, int x, int y)
{
	char	*data;

	data = frame.addr + (y * frame.line_length
			+ x * (frame.bits_per_pixel / 8));
	return (*(int *)data);
}

void	draw_zoomed_frame(t_frame orig_frame, t_frame *zoomed_frame)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y < GAME_HEIGHT)
	{
		x = 0;
		while (x < GAME_WIDTH)
		{
			color = get_pixel(orig_frame, x, y);
			my_mlx_pixel_put(zoomed_frame, x * 2, y * 2, color);
			my_mlx_pixel_put(zoomed_frame, x * 2 + 1, y * 2, color);
			my_mlx_pixel_put(zoomed_frame, x * 2, y * 2 + 1, color);
			my_mlx_pixel_put(zoomed_frame, x * 2 + 1, y * 2 + 1, color);
			x++;
		}
		y++;
	}
}

void	zoom(t_game *game)
{
	int		new_width;
	int		new_height;
	t_frame	zoomed_frame;

	new_height = GAME_HEIGHT * 2;
	new_width = GAME_WIDTH * 2;
	zoomed_frame.img = mlx_new_image(game->mlx, new_width, new_height);
	zoomed_frame.addr = mlx_get_data_addr(zoomed_frame.img,
			&zoomed_frame.bits_per_pixel, &zoomed_frame.line_length,
			&zoomed_frame.endian);
	draw_zoomed_frame(game->frame, &zoomed_frame);
	mlx_destroy_image(game->mlx, game->frame.img);
	game->frame = zoomed_frame;
}
