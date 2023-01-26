#include "cub3d.h"

void	reset_player_movement(t_player *player)
{
	player->dx = 0;
	player->dy = 0;
}

void	get_player_input_directions(t_player *player, t_game *game)
{
	if (player->up && !player->down)
	{
		player->dx = (int)(PLAYER_SPEED * cos(player->angle) * 20);
		player->dy = (int)(PLAYER_SPEED * sin(player->angle) * 20);
	}
	if (player->down && !player->up)
	{
		player->dx = (int)-(PLAYER_SPEED * cos(player->angle) * 20);
		player->dy = (int)-(PLAYER_SPEED * sin(player->angle) * 20);
	}
	if (player->strafe_l)
	{
		player->dx = (int)(PLAYER_SPEED * cos((player->angle + ((3 * M_PI )/ 2))) * 20);
		player->dy = (int)(PLAYER_SPEED * sin((player->angle + ((3 * M_PI )/ 2))) * 20);
	}
	if (player->strafe_r)
	{
		player->dx = (int)(PLAYER_SPEED * cos(player->angle + (M_PI / 2)) * 20);
		player->dy = (int)(PLAYER_SPEED * sin(player->angle + (M_PI / 2)) * 20);
	}
	if (player->left)
		player->angle = (player->angle - PLAYER_TURN_SPEED);
	if (player->right)
		player->angle = (player->angle + PLAYER_TURN_SPEED);
	if (!check_player_colision(game->map,
			(game->player.x + (game->player.dx * 2))
			/ GRID_UNIT, game->player.y / GRID_UNIT))
		game->player.x += game->player.dx;
	if (!check_player_colision(game->map, (game->player.x) / GRID_UNIT,
			(game->player.y + (game->player.dy * 2)) / GRID_UNIT))
		game->player.y += game->player.dy;
}

void	set_player_direction(t_player *player)
{
	if (player->angle > 2 * M_PI)
		player->angle -= 2 * M_PI;
	else if (player->angle < 0)
		player->angle += 2 * M_PI;
	if (cos(player->angle >= 0))
		player->x_dir = -1;
	else
		player->x_dir = 1;
	if (sin(player->angle >= 0))
		player->y_dir = 1;
	else
		player->y_dir = -1;
}
