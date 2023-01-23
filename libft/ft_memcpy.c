/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:09:02 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 12:09:08 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*tab;
	char		*tab2;
	size_t		i;

	tab = src;
	tab2 = dest;
	i = 0;
	if ((dest == 0) && (src == 0))
		return (dest);
	while (i < n)
	{
		tab2[i] = tab[i];
		i++;
	}
	return (dest);
}
