/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:02:18 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/12 09:23:08 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (s1 == 0)
		return (0);
	i = 0 ;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) != NULL)
	{
		i++;
	}
	while ((ft_strchr(set, s1[j]) != NULL) && (j != i))
	{
		j--;
	}
	str = ft_substr(s1, i, ((j - i) + 1));
	if (!str)
		return (0);
	return (str);
}
