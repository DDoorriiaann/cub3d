/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:02:40 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/05/17 14:08:01 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strjoins(char *s1, char *s2)
{
	size_t	i;
	char	*str;

	str = NULL;
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	if (s2 == NULL)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((sizeof(char)) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	ft_strlcpy(str, s1, i + 1);
	ft_strlcpy(str + ft_strlen(s1), s2, i + 1);
	free(s1);
	s1 = NULL;
	return (str);
}
