/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:11:33 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 12:11:38 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*str2;
	int		i;
	size_t	size;

	i = 0;
	str = (char *) s;
	size = ft_strlen(str);
	str2 = malloc(sizeof(*str) * size + 1);
	if (str2 == NULL)
		return (str2);
	str2[size] = '\0';
	while (str[i] != '\0')
	{
		ft_strlcpy(str2, str, size + 1);
		i++;
	}
	return (str2);
}
