#include "cub3d.h"

int	calculate_offset(double angle_check)
{
	if (angle_check >= 0)
		return (-1);
	else
		return (1);
}

int	find_collision(t_game *game, t_player player)
{
	int		next_x;
	int		next_y;
	int		cos_offset;
	int		sin_offset;
	float	angle;

	cos_offset = calculate_offset(cos(player.angle));
	sin_offset = calculate_offset(sin(player.angle));
	angle = player.angle * (180 / M_PI);
	
	
	if (player.up)
	{
		next_x = (floor(player.x - PLAYER_SPEED * cos(player.angle)) + (PLAYER_SIZE * cos_offset)) / GRID_UNIT;
		next_y = (floor(player.y - PLAYER_SPEED * sin(player.angle)) + (PLAYER_SIZE * sin_offset)) / GRID_UNIT;
		if (game->map.matrix[next_y][next_x] == '1')
			return (TRUE);
	}
	if (player.down)
	{
		next_x = (floor(player.x + PLAYER_SPEED * cos(player.angle)) - (PLAYER_SIZE * cos_offset)) / GRID_UNIT;
		next_y = (floor(player.y + PLAYER_SPEED * sin(player.angle)) - (PLAYER_SIZE * sin_offset)) / GRID_UNIT;
		if (game->map.matrix[next_y][next_x] == '1')
			return (TRUE);
	}
	return (FALSE);
}