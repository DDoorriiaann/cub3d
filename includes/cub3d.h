#ifndef CUB3D
# define CUB3D
# include <stdio.h>
# include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"
#include <errno.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# define GAME_WIDTH 1000
# define GAME_HEIGHT 500
# define MINIMAP_HEIGHT 500
# define MINIMAP_WIDTH 500
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500
# define GRID_UNIT 50
# define PLAYER_SIZE 10
# define PLAYER_SPEED 0.8
# define PLAYER_TURN_SPEED 0.02
# define TRUE 1
# define FALSE 0
# define FOV 1.20428 // 69 degrees

typedef struct s_data
{
	char	*NO;
	char	*SO;
	char 	*EA;
	char 	*WE;
	char 	*F;
	char 	*C;
	int		count;
}	t_data;

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
}				t_frame;

typedef struct s_map
{
	char		**matrix;
	int			map_width;
	int			map_height;
}	t_map;


typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_frame		frame;
	t_player	player;
	t_map		map;	
}	t_game;

typedef struct ray
{
	float	x;
	float	y;
	float	distance;
	int		collision;
	float	wall_height;
	int		x_dir;
	int		y_dir;
	float	x_offset;
	float	y_offset;
	float	x_first_offset;
	float	y_first_offset;
}	t_ray;

//DRAWING

void	my_mlx_pixel_put(t_frame *frame, int x, int y, int color);
void	draw_grid(t_game *game);
void	draw_map(t_game *game);
void 	draw_target(t_game *game, t_player player, int endX, int endY);
void	draw_fov(t_game *game, t_player player);
void	mlx_line_horizontal(t_frame frame, int x, int y, int len, int color);
void	draw_line_bresenham(t_game *game, int x1, int y1, int x2, int y2);
void	draw_line(t_game *game, t_player player, int x2, int y2);
void	draw_wall_ray(t_game *game, t_ray ray, int ray_count);
void	mlx_circle_filled(t_game *game,
			int x, int y, int r, int color);

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

//INIT

void	    init_data(t_data *data, t_game *game);
void        init_player(t_game *game);

//PARSING

int         check_map_description(t_data *data, int fd);
char	    *save_path(t_data *data, char *line);
int		    check_file_extension(char *file_name);
int		    open_fd(char *file);
int		    read_fd(t_data *data, t_game *game, int fd);
void	    check_floor(t_data *data);
int         ft_strlen_path(int i, const char *line);
void	    check_empty_string(t_data *data, const char * line);
void        check_is_number(char *tmp);
int		    ft_number_comma(const char *str);
void        check_is_valid_color(int color);
void        check_ceiling(t_data *data);
char        *fetch_map_to_string(int fd);
void        fill_map_and_count_lines(t_game *game, char *tmp);
int         check_valid_map(t_game *game);
int         valid_character(t_game *game);
int         fill_player_position(t_game *game);

//ERROR

int		    ft_error(char *message);

//FREE

void    free_data(t_data *data);

#endif
