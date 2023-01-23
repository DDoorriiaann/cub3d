/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:09:15 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 12:09:19 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*tab;
	char		*tab2;
	size_t		i;

	i = 0;
	tab = src;
	tab2 = dest;
	if ((dest == 0) && (src == 0))
		return (dest);
	while (i < n)
	{
		if (tab < tab2)
		{
			tab2[(n - 1) - i] = tab[(n - 1) - i];
		}
		else
		{
			tab2[i] = tab[i];
		}
		i++;
	}
	return (dest);
}
