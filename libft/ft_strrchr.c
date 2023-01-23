/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:19:40 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 12:19:43 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*t;
	char	u;
	char	*j;

	u = c;
	t = (char *) s;
	j = t;
	while (*t != '\0')
		t++;
	while (*t != *j)
	{
		if (*t == u)
			return (t);
		t--;
	}
	if (*t == u)
		return (t);
	if (u == 0)
		return (t);
	return (NULL);
}
