#include "cub3d.h"

void    free_data(t_data *data)
{
	if (data->NO)
    	free(data->NO);
	if (data->SO)
		free(data->SO);
	if (data->EA)
		free(data->EA);
	if (data->WE)
		free(data->WE);
	if (data->F)
		free(data->F);
	if (data->C)
		free(data->C);
}