#ifndef CUB3D
# define CUB3D
# include <stdio.h>

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

#endif
