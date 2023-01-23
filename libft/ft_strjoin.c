/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:32:57 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/11 12:24:23 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

//	if ((s1 == 0) || (s2 == 0))
//		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
    if (s1)
	    ft_strlcpy(str, s1, i + 1);
	ft_strlcpy(str + ft_strlen(s1), s2, i + 1);
	return (str);
}
