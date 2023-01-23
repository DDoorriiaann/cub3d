/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:13:01 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 12:13:05 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	i = 0;
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while (t1[i] && t2[i])
	{
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
		i++;
	}
	return (t1[i] - t2[i]);
}
