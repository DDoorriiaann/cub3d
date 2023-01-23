/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:09:21 by ybaudoui          #+#    #+#             */
/*   Updated: 2023/01/17 15:11:08 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char *save)
{
	int		i;
	char	*tmp;

	i = 0;
	if (*save == '\0')
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	tmp = ft_substr(save, 0, i + 1);
	return (tmp);
}

char	*ft_save(char *save)
{
	int		i;
	char	*end;
	char	*tmp;

	i = 0;
	end = ft_strchr(save, '\n');
	if (*save == '\0' || !end || !*(end + 1))
	{	
		free(save);
		return (NULL);
	}
	while (save[i] && save[i] != '\n')
		i++;
	tmp = ft_substr(save, i + 1, ft_strlen(&save[i]));
	free(save);
	save = tmp;
	return (save);
}

char	*ft_read(int fd, char *save)
{
	char	*buff;
	int		ret;

	ret = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	while (ft_strchr(buff, '\n') == NULL && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
		{
			free(buff);
			buff = NULL;
			return (NULL);
		}
		buff[ret] = '\0';
		save = ft_strjoins(save, buff);
	}
	free(buff);
	buff = NULL;
	return (save);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	static char	*save[1024];

	if (fd < 0)
		return (NULL);
	save[fd] = ft_read(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	tmp = ft_getline(save[fd]);
	save[fd] = ft_save(save[fd]);
	return (tmp);
}
