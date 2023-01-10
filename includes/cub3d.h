#ifndef CUB3D
# define CUB3D
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500
# define MINIMAP_SIZE 500
# define GRID_SIZE 50
# define PLAYER_SIZE 5
# define PLAYER_SPEED 3
# define PLAYER_TURN_SPEED M_PI / 4 / 10
# define TRUE 1
# define FALSE 0

typedef struct s_player
{
	double	x;
	double	y;
	int		up;
	int		down;
	int		left;
	int		right;
	double	angle;
	int		line_length;
}	t_player;

typedef struct	s_frame {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_frame;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_frame		frame;
	t_player	player;
}	t_game;


//DRAWING

void	my_mlx_pixel_put(t_frame *frame, int x, int y, int color);
void	draw_grid(t_game *game);
void 	draw_target(t_game *game, t_player player, int endX, int endY);
void	mlx_line_horizontal(t_frame frame, int x, int y, int len, int color);
void	draw_line_bresenham(t_game *game, int x1, int y1, int x2, int y2);
void	mlx_circle_filled(t_game *game,
			int x, int y, int r, int color);

//INPUT MANAGEMENT

int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);

//GAME

void	quit_game(t_game *game);
int		game_routine(t_game *game);

#endif
