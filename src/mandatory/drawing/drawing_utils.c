#include "cub3d.h"

void draw_target(t_game *game, t_player player, int endX, int endY)
{
	double deltaX = (endX - player.x);
	double deltaY = (endY - player.y);
	double pixelX = player.x;
	double pixelY = player.y;

	pixelX += deltaX;
	pixelY += deltaY;
	//if (pixelX < WINDOW_WIDTH && pixelY < WINDOW_HEIGHT && pixelX > 0 && pixelY > 0)
		//mlx_circle_filled(game, pixelX, pixelY, 4, color);
	draw_line(game, game->player, (int)(game->player.x - (cos(game->player.angle) * game->player.line_length)), (int)(game->player.y - (sin(game->player.angle) * game->player.line_length)));	
	draw_fov(game, game->player);
}

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
		draw_line(game, player, (int)(game->player.x - (cos(drawn_angle) * game->player.line_length)), (int)(game->player.y - (sin(drawn_angle) * game->player.line_length)));
		drawn_angle += step;
		iterations--;
	}
}
