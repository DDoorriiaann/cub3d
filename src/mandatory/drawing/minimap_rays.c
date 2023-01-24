#include "cub3d.h"

void	init_trace(t_game *game, t_player player, t_raydraw *trace, t_ray ray)
{
	trace->distance = 1;
	trace->x = (int)((player.x / 128.0) * game->minimap.grid_size);
	trace->y = (int)((player.y / 128.0) * game->minimap.grid_size);
	trace->x2 = (int)((ray.x / 128.0) * game->minimap.grid_size);
	trace->y2 = (int)((ray.y / 128.0) * game->minimap.grid_size);
	trace->delta_x = abs(trace->x2 - trace->x);
	trace->delta_y = abs(trace->y2 - trace->y);
	if (trace->x < trace->x2)
		trace->step_x = 1;
	else
		trace->step_x = -1;
	if (trace->y < trace->y2)
		trace->step_y = 1;
	else
		trace->step_y = -1;
	if (trace->delta_x > trace->delta_y)
		trace->err = (trace->delta_x) / 2;
	else
		trace->err = -(trace->delta_y) / 2;
}

void	draw_decision(t_raydraw *trace)
{
	if (trace->err2 > -trace->delta_x)
	{
		trace->err -= trace->delta_y;
		trace->x += trace->step_x;
	}
	if (trace->err2 < trace->delta_y)
	{
		trace->err += trace->delta_x;
		trace->y += trace->step_y;
	}
}

void	draw_ray(t_game *game, t_player player, t_ray ray)
{
	t_raydraw	trace;

	init_trace(game, player, &trace, ray);
	while (1)
	{
		if (trace.x < game->minimap.width && trace.y < game->minimap.height
			&& trace.x > 0 && trace.y > 0)
			my_mlx_pixel_put(&game->minimap.frame, trace.x, trace.y,
				get_fogged_color((trace.distance * trace.distance) * 2,
					0xFF0000));
		else
			break ;
		if (trace.x == trace.x2 && trace.y == trace.y2)
			break ;
		trace.err2 = trace.err;
		draw_decision(&trace);
		trace.distance++;
	}
}
