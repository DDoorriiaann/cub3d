#ifndef CUB3D
# define CUB3D
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"
# include <errno.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../libft/libft.h"
# define GAME_WIDTH 400
# define GAME_HEIGHT 300
# define MINIMAP_HEIGHT 50
# define MINIMAP_WIDTH 50
# define WINDOW_WIDTH 400
# define WINDOW_HEIGHT 300
# define GRID_UNIT 128
# define PLAYER_SIZE 1
# define PLAYER_SPEED 0.5
# define PLAYER_TURN_SPEED 0.03
# define TRUE 1
# define FALSE 0
# define FOV 1.0

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
	int	x;
	int	y;
	int	dx;
	int	dy;
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

typedef struct s_minimap
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		grid_size;
	t_frame	frame;
}	t_minimap;

typedef	struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;

typedef struct s_textures
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_frame		frame;
	t_frame		zoomed_frame;
	t_frame		minimap_mask;
	t_player	player;
	t_map		map;
	t_minimap	minimap;
	t_textures	textures;
	int			floor_color;
	int			ceiling_color;
}	t_game;

typedef struct ray
{
	double	x;
	double	y;
	double	depth;
    double  angle;
	int		collision;
	double	wall_height;
	int		x_dir;
	int		y_dir;
	double	orig_x;
	double	orig_y;
	double	x_map;
	double	y_map;
	double	sin_a;
	double	cos_a;
	double	x_vert;
	double	y_vert;
	double	x_hor;
	double	y_hor;
	double	depth_vert;
	double	depth_hor;
	double	delta_depth;
	double	dx;
	double	dy;
	int		tile_vert[2];
	int		tile_hor[2];
}	t_ray;

typedef struct s_ray_draw
{
	int	delta_x;
	int	delta_y;
	int	step_x;
	int	step_y;
	int	x;
	int	y;
	int	x2;
	int	y2;
	int	err;
	int	err2;
	int	distance;
}	t_raydraw;

typedef struct s_minimap_draw
{
	int	x;
	int	y;
	int	player_x;
	int	player_y;
	int	src_x;
	int	src_y;
}	t_minimap_draw;

//DRAWING

void	my_mlx_pixel_put(t_frame *frame, int x, int y, int color);
void	draw_map(t_game *game);
void	draw_line_horizontal(t_frame frame, int x, int y, int len);
void	draw_protected_line_horizontal(t_game *game, t_frame minimap, int x, int y, int len, int color);
void	draw_ray(t_game *game, t_player player, t_ray ray);
void	draw_wall_ray(t_game *game, t_ray ray, int ray_count);
void	draw_disc(t_game *game,
			int x, int y, int r);
void	zoom(t_game *game);
int		get_pixel(t_frame frame, int x, int y);
void	draw_minimap(t_game *game, t_frame minimap);
void	draw_minimap_background(t_game *game);
void	draw_square(t_game *game, int x, int y, int color);
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

int	check_collision(t_map map, int x, int y);
int	check_player_colision(t_map map, int x, int y);

//INIT

void	    init_data(t_data *data, t_game *game);
void        init_player(t_game *game);

//PARSING

int         check_map_description(t_data *data, int fd);
char	    *save_path(t_data *data, char *line);
int		    check_file_extension(char *file_name);
int		    open_fd(char *file);
int		    read_fd(t_data *data, t_game *game, int fd);
int 	    check_floor(t_data *data);
int         ft_strlen_path(int i, const char *line);
void	    check_empty_string(t_data *data, const char * line);
void        check_is_number(char *tmp);
int		    ft_number_comma(const char *str);
void        check_is_valid_color(int color);
int         check_ceiling(t_data *data);
char        *fetch_map_to_string(int fd);
void        fill_map_and_count_lines(t_game *game, char *tmp);
int         check_valid_map(t_game *game);
int         valid_character(t_game *game);
int         fill_player_position(t_game *game);
int         player_exist(t_game *game);

//ERROR

int		    ft_error(char *message);

//FREE

void    free_data(t_data *data);
void    free_arr(char **arr);

#endif
