#ifndef CUB3D
# define CUB3D
# include <stdio.h>

typedef struct s_player
{
	int	x;
	int	y;
	int	up;
	int	down;
	int	left;
	int	right;
}	t_player;

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_img_data	img;
	t_player	player;
}	t_game;

#endif
