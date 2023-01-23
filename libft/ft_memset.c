/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:09:26 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 12:09:29 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char				*tab;
	long unsigned int	i;

	i = 0;
	tab = s;
	while (i < n)
	{	
		tab[i] = c;
		i++;
	}
	return (s);
}
