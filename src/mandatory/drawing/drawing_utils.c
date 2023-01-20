#include "cub3d.h"

void	draw_fov(t_game *game, t_player player)
{
	double	drawn_angle;
	int	iterations;
	float step;
	
	step = (float)FOV / (float)WINDOW_WIDTH;

	iterations = WINDOW_WIDTH;
	drawn_angle = player.angle - (FOV / 2);
	while (iterations >= 0)
	{
		draw_ray(game, player, (int)(game->player.x - (cos(drawn_angle) * game->player.line_length)), (int)(game->player.y - (sin(drawn_angle) * game->player.line_length)));
		drawn_angle += step;
		iterations--;
	}
}

int get_pixel(t_frame frame, int x, int y)
{
    char *data =  frame.addr + (y * frame.line_length + x * (frame.bits_per_pixel / 8));
    return *(int*)data;
}

// void set_pixel(t_frame frame, int x, int y, int color) {
//     int bpp = frame.bits_per_pixel / 8;
//     char *data = frame.addr + y * frame.width + x * bpp;
//     *(int*)data = color;
// }
void	zoom(t_game *game)
{
  	int new_width = GAME_WIDTH * 2;
    int new_height = GAME_HEIGHT * 2;
	t_frame zoomed_frame;

	zoomed_frame.img = mlx_new_image(game->mlx, new_width, new_height);
	zoomed_frame.addr = mlx_get_data_addr(zoomed_frame.img, &zoomed_frame.bits_per_pixel, &zoomed_frame.line_length, &zoomed_frame.endian);
    int x, y;
    for (y = 0; y <  GAME_HEIGHT; y++) {
        for (x = 0; x <  GAME_WIDTH; x++) {
            int color = get_pixel(game->frame, x, y);
            my_mlx_pixel_put(&zoomed_frame, x * 2, y * 2, color);
            my_mlx_pixel_put(&zoomed_frame, x * 2 + 1, y * 2, color);
            my_mlx_pixel_put(&zoomed_frame, x * 2, y * 2 + 1, color);
            my_mlx_pixel_put(&zoomed_frame, x * 2 + 1, y * 2 + 1, color);
        }
    }
    mlx_destroy_image(game->mlx, game->frame.img);
    game->frame = zoomed_frame;
}