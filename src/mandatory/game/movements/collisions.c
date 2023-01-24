#include "cub3d.h"

int	calculate_offset(double angle_check)
{
	if (angle_check >= 0)
		return (-1);
	else
		return (1);
}

int	check_player_colision(t_map map, int x, int y)
{
	if (x >= 0 && y >= 0 && x < map.width && y < map.height
		&& map.matrix[y][x] == '1')
	{
		return (TRUE);
	}
	else
		return (FALSE);
}

int	check_collision(t_map map, int x, int y)
{
	if (x >= 0 && y >= 0 && x < map.width && y < map.height
		&& map.matrix[y][x] == '1')
	{
		return (TRUE);
	}
	else
		return (FALSE);
}
