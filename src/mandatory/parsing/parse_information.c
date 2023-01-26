#include "cub3d.h"

int	get_info(t_data *data, char *line)
{
	if ((strncmp(line, "NO ", 3) == 0) && data->NO == NULL)
		data->NO = save_path(data, line);
	else if ((strncmp(line, "SO ", 3) == 0) && data->SO == NULL)
		data->SO = save_path(data, line);
	else if ((strncmp(line, "EA ", 3) == 0) && data->EA == NULL)
		data->EA = save_path(data, line);
	else if ((strncmp(line, "WE ", 3) == 0) && data->WE == NULL)
		data->WE = save_path(data, line);
	else if ((strncmp(line, "F ", 2) == 0) && data->F == NULL)
		data->F = save_path(data, line);
	else if ((strncmp(line, "C ", 2) == 0) && data->C == NULL)
		data->C = save_path(data, line);
	else if (line[0] == '\n')
	{
		free(line);
		return (0);
	}
	else if (line[0] != '\n')
	{
		free(line);
		return (ERROR);
	}
	data->count++;
	return (0);
}

int	check_map_description(t_data *data, int fd)
{
	char	*line;

	while (data->count != 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else
		{
			if (get_info(data, line) == ERROR)
				return (ERROR);
		}
	}
	if (data->count != 6)
		return (ERROR);
	return (0);
}
