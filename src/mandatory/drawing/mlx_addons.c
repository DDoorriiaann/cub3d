#include "cub3d.h"

void	my_mlx_pixel_put(t_frame *frame, int x, int y, int color)
{
	char	*dst;

	dst = frame->addr + (y * frame->line_length + x *
		(frame->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}