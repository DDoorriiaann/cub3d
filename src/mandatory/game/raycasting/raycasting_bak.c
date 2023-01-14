#include "cub3d.h"

double normalize_angle(double angle)
{
    if (angle >= 2 * M_PI)
        angle -= 2 * M_PI;
    else if (angle < 0)
        angle += 2 * M_PI;
    return (angle);
}

int scan_done(t_ray *ray)
{
    int i;

    i = 0;
    while (i < 5)
    {
        if (ray[i].scan_done == FALSE)
            return (FALSE);
        i++;
    }
    return (TRUE);
}

void	raycasting(t_game *game, t_player player)
{
    int     i;
	int		ray_count;
	float	step;
	t_ray	ray[5];
	int		iteration;
    t_ray   cur_ray;

	step = (((float)FOV / (float)WINDOW_WIDTH));
	ray_count = 0;
	ray[0].angle = player.angle;
    ray[1].angle = player.angle;
    ray[2].angle = player.angle - (FOV / 2);
    ray[3].angle  = player.angle;
    ray[4].angle  = player.angle + (FOV / 2);
    ray[1].scan_done = 1;
    ray[2].scan_done = 1;
    ray[3].scan_done = 1;
    ray[4].scan_done = 1;
    cur_ray = ray[2];

//	while (scan_done(ray) == FALSE)
    while (cur_ray.angle < WINDOW_WIDTH)
	{
        cur_ray = ray[2];
        i = 0;
        while (i < 5)
        {
            ray[i].angle = normalize_angle(ray[i].angle);
            i++;
        }

        cur_ray.collision = 0;
        cur_ray.distance = 0;
        cur_ray.x = player.x;
        cur_ray.y = player.y;
		if (cos(cur_ray.angle) > 0)
            cur_ray.x_dir = -1;
		else
            cur_ray.x_dir = 1;
		if (sin(cur_ray.angle) > 0)
            cur_ray.y_dir = -1;
		else
            cur_ray.y_dir = 1;
//		printf("ray x_dir: %d\n", ray.x_dir);
//		printf("ray y_dir: %d\n", ray.y_dir);
		iteration = 2;
		while (cur_ray.collision == 0  && cur_ray.distance < 257)
		// while (ray.collision == 0 && ray.distance < 257)
		{
            cur_ray.x -= cos(cur_ray.angle) / 4;
            cur_ray.y -= sin(cur_ray.angle) / 4;
			
			if (cur_ray.x >= 0 && cur_ray.y >= 0 && cur_ray.x < game->map.width * GRID_UNIT && cur_ray.y < game->map.height * GRID_UNIT)
			{
				if (game->map.matrix[(int)(cur_ray.y / GRID_UNIT)][(int)(cur_ray.x / GRID_UNIT)] == '1')
				{
				//printf("collision\n");
                    cur_ray.collision = 1;
				break ;
				}
//				else
//				{
//					while (((int)floor(ray.x) % GRID_UNIT) == 0 || ((int)floor(ray.y) % GRID_UNIT) == 0)
//					{
//						ray.x += cos(drawn_angle);
//						ray.y += sin(drawn_angle);
//					}
//				}
			}
            cur_ray.distance = sqrt(((cur_ray.x - player.x) * (cur_ray.x - player.x))  + ((cur_ray.y - player.y) * (cur_ray.y - player.y)));
			//Fisheye correction :
            cur_ray.distance = cur_ray.distance * cos(player.angle - cur_ray.angle);
			// if (ray.distance > 256)
			// 	ray.distance = 257;
			//printf("ray distance : %f\n", ray.distance);
		}
		//printf("\n");
        cur_ray.wall_height = ((WINDOW_HEIGHT / 2) / (cur_ray.distance / (GRID_UNIT * 3.4)));
		//printf("ray distance : %f\n", ray.distance);
		//printf("ray wall height : %f\n", ray.wall_height);
		draw_line(game, player, (int)cur_ray.x, (int)cur_ray.y);
		//if (ray.collision == 1)
		draw_wall_ray(game, cur_ray, ray_count);
        cur_ray.angle += step;
		ray_count+=1;
        if (ray_count == WINDOW_WIDTH)
            ray[0].scan_done = TRUE;
	}
//	printf("DOOOOOOOONE\n");
}