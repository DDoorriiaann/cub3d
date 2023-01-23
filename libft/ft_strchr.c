/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:10:32 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 12:10:36 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*t;
	char	u;

	u = c;
	t = (char *) s;
	while (*t != '\0')
	{
		if (*t == u)
		{
			return (t);
		}
		t++;
	}
	if (u == 0)
	{	
		return (t);
	}
	return (NULL);
}
