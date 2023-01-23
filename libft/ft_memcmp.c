/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:08:46 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 12:08:53 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tab1;
	unsigned char	*tab2;

	tab1 = (unsigned char *) s1;
	tab2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (tab1[i] > tab2[i])
			return (1);
		else if (tab1[i] < tab2[i])
			return (-1);
		i++;
	}
	return (0);
}
