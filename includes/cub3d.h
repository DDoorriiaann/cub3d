#ifndef CUB3D
# define CUB3D
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# define GAME_WIDTH 320
# define GAME_HEIGHT 240
# define MINIMAP_HEIGHT 50
# define MINIMAP_WIDTH 50
# define WINDOW_WIDTH 320
# define WINDOW_HEIGHT 240
# define GRID_UNIT 5
# define PLAYER_SIZE 1
# define PLAYER_SPEED 0.15
# define PLAYER_TURN_SPEED 0.02
# define TRUE 1
# define FALSE 0
# define FOV 1.0 // 60 degrees

typedef struct s_player
{
	double	x;
	double	y;
	int		up;
	int		down;
	int		left;
	int		right;
	double	angle;
	int		x_dir;
	int		y_dir;
	int		line_length;
}	t_player;

typedef struct	s_frame {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_frame;

typedef struct s_map
{
	char		**matrix;
	int			width;
	int			height;
}	t_map;


typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_frame		frame;
	t_frame		minimap;
	t_frame		zoomed_frame;
	t_player	player;
	t_map		map;	
	int			floor_color;
	int			ceiling_color;
}	t_game;

typedef struct ray
{
	float	x;
	float	y;
	float	distance;
    double   angle;
	int		collision;
    int     scan_done;
    int     collision_cel[2];
	float	wall_height;
	int		x_dir;
	int		y_dir;
	int		x_step;
	int		y_step;
	float	x_offset_len;
	float	y_offset_len;
	float	x_offset;
	float	y_offset;
	float	x_first_offset;
	float	y_first_offset;
	float 	unit_step_size;
}	t_ray;

//DRAWING

void	my_mlx_pixel_put(t_frame *frame, int x, int y, int color);
void	draw_grid(t_game *game);
void	draw_map(t_game *game);
void 	draw_target(t_game *game, t_player player, int endX, int endY);
void	draw_fov(t_game *game, t_player player);
void	mlx_line_horizontal(t_frame frame, int x, int y, int len, int color);
void	draw_protected_line_horizontal(t_game *game, t_frame minimap, int x, int y, int len, int color);
void	draw_line(t_game *game, t_player player, int x2, int y2);
void	draw_wall_ray(t_game *game, t_ray ray, int ray_count);
void	mlx_circle_filled(t_game *game,
			int x, int y, int r, int color);
void	zoom(t_game *game);
int		get_pixel(t_frame frame, int x, int y);
void	draw_minimap(t_game *game, t_frame minimap);
void	draw_floor_and_ceiling(t_frame frame);

//RAYCASTING

void	raycasting(t_game *game, t_player player);

//INPUT MANAGEMENT

int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);

//GAME

void	quit_game(t_game *game);
int		game_routine(t_game *game);

//MOVEMENTS

int	find_collision(t_game *game, t_player player);

#endif
