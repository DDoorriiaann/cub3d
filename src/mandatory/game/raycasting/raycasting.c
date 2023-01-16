#include "cub3d.h"


// void	raycasting(t_game *game, t_player player)
// {
// 	double	drawn_angle;
// 	int		ray_count;
// 	float	step;
// 	t_ray	ray;
// 	int		iteration;

// 	step = (((float)FOV / (float)WINDOW_WIDTH));
// 	ray_count = 0;
// 	drawn_angle = player.angle - (FOV / 2);
// 	while (ray_count < WINDOW_WIDTH)
// 	{
// 		 if (drawn_angle >= 2 * M_PI)
// 		 	drawn_angle -= 2 * M_PI;
// 		 else if (drawn_angle < 0)
// 		 	drawn_angle += 2 * M_PI;
// 		ray.collision = 0;
// 		ray.distance = 0;
// 		ray.x = player.x;
// 		ray.y = player.y;
// 		if (cos(drawn_angle) > 0)
// 			ray.x_dir = 1;
// 		else
// 			ray.x_dir = -1;
// 		if (sin(drawn_angle) > 0)
// 			ray.y_dir = 1;
// 		else
// 			ray.y_dir = -1;
// 		iteration = 2;
// 		float deltaDistX = fabs(1 / cos(drawn_angle));
// 		float deltaDistY = fabs(1 / sin(drawn_angle));
// 		int currCellX = (int)ray.x;
// 		int currCellY = (int)ray.y;
// 		//int stepX;
// 		//int stepY;
// 		int test = 0;
// 		while (test++ < 20) {
// 			// Calculer les distances de côté
// 			if (ray.x_dir < 0) {
// 				ray.x += deltaDistX;
// 				currCellX += -1;
// 			} else {
// 				ray.x += deltaDistX;
// 				currCellX += 1;
// 			}
// 			if (ray.y_dir < 0) {
// 				ray.y += deltaDistY;
// 				currCellY += -1;
// 			} else {
// 				ray.y += deltaDistY;
// 				currCellY += 1;
// 			}
// 			// Vérifier une collision
// 			if (currCellX >= 0 && currCellY >= 0 && currCellX < game->map.width && currCellY < game->map.height)
// 			{
// 				if (game->map.matrix[currCellY][currCellX] == '1')
// 				{
// 				ray.collision = 1;
// 				break ;
// 				}
// 			}
// 		}
// 			ray.distance = sqrt(((ray.x - player.x) * (ray.x- player.x))  + ((ray.y - player.y) * (ray.y - player.y)));
// 			//Fisheye correction :
// 			ray.distance = ray.distance * cos(player.angle - drawn_angle);
// 		// Sortir de la boucle lorsque le rayon sort des limites de la carte
// 		if (currCellX < 0 || currCellX >= game->map.width || currCellY < 0 || currCellY >= game->map.height)
// 			break;
// 	}
// 	ray.wall_height = ((WINDOW_HEIGHT / 2) / (ray.distance / (GRID_UNIT * 3.4)));
// 	draw_line(game, player, (int)ray.x, (int)ray.y);
// 	draw_wall_ray(game, ray, ray_count);
// 	ray_count++;
// 	drawn_angle += step;
// }
void	raycasting(t_game *game, t_player player)
{
	double	drawn_angle;
	int		ray_count;
	float	step;
	t_ray	ray;
	int		iteration;

	step = (((float)FOV / (float)WINDOW_WIDTH));
	ray_count = 0;
	drawn_angle = player.angle - (FOV / 2);
	
	while (ray_count < WINDOW_WIDTH)
	{
		 if (drawn_angle >= 2 * M_PI)
		 	drawn_angle -= 2 * M_PI;
		 else if (drawn_angle < 0)
		 	drawn_angle += 2 * M_PI;
		ray.collision = 0;
		ray.distance = 0;
		ray.x = player.x;
		ray.y = player.y;

		if (cos(drawn_angle) > 0)
			ray.x_dir = -1;
		else
			ray.x_dir = 1;
		if (sin(drawn_angle) > 0)
			ray.y_dir = -1;
		else
			ray.y_dir = 1;

		iteration = 2;
		while (ray.collision == 0  && ray.distance < 400)
		{
				ray.x -= cos(drawn_angle) / 8;
				ray.y -= sin(drawn_angle) / 8;
			if (ray.x >= 0 && ray.y >= 0 && ray.x < game->map.width * GRID_UNIT && ray.y < game->map.height * GRID_UNIT)
			{
				if (game->map.matrix[(int)(ray.y / GRID_UNIT)][(int)(ray.x / GRID_UNIT)] == '1')
				{
					ray.collision = 1;
					break ;
				}
			}
			ray.distance = sqrt(((ray.x - player.x) * (ray.x - player.x))  + ((ray.y - player.y) * (ray.y - player.y)));
			//Fisheye correction :
			ray.distance = ray.distance * cos(player.angle - drawn_angle);
		}
		ray.wall_height = ((WINDOW_HEIGHT / 2) / (ray.distance / (GRID_UNIT * 2.2)));
		ray.angle = drawn_angle * (180/ M_PI);
		draw_line(game, player, (int)ray.x, (int)ray.y);
		draw_wall_ray(game, ray, ray_count);
		drawn_angle += step;
		ray_count+=1;
	}
}