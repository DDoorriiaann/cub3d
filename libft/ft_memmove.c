/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:07:21 by dguet             #+#    #+#             */
/*   Updated: 2022/03/30 15:24:50 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest2;
	char	*src2;

	dest2 = (char *)dest;
	src2 = (char *)src;
	if (n == 0)
		return (dest);
	if (dest < src)
	{
		i = -1;
		while (++i < n)
			dest2[i] = src2[i];
	}
	if (dest > src)
	{
		while (n--)
			dest2[n] = src2[n];
	}
	return (dest);
}
