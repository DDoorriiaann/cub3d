#include "cub3d.h"

int	ft_strlen_path(int i, const char *line)
{
	int	count;

	count = 0;
	while (line[i])
	{
		count++;
		i++;
	}
	return (count);
}

void	check_empty_string(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\n' || line[i] == '\0')
	{
		ft_error("You have an empty information\n");
		free_data(data);
		free(line);
		exit (1);
	}
}

static int	ft_is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
		return (ERROR);
	while (str[i] && str[i] != '\n')
	{
		if (str[i] < 48 || str[i] > 57)
			return (ERROR);
		i++;
	}
	return (0);
}

int	check_is_number(char *tmp)
{
	int	i;

	i = ft_is_number(tmp);
	if (i == ERROR)
	{
		ft_error("Invalid color format\n");
		return (ERROR);
	}
	return (0);
}

int	ft_number_comma(const char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	return (j);
}
