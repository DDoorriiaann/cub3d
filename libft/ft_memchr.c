/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:08:33 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 12:08:38 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tab;
	unsigned char	d;

	i = 0;
	d = (unsigned char) c;
	tab = (unsigned char *) s;
	while (i < n)
	{	
		if (tab[i] == d)
			return (&tab[i]);
		i++;
	}
	return (NULL);
}
