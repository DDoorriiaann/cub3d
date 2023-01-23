/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:11:48 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 12:11:51 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = ft_strlen(dst);
	i = 0;
	j = 0;
	if (size <= k)
		return (ft_strlen(src) + (size));
	while (dst[i] != '\0')
	{
		i++;
	}
	while ((src[j] != '\0') && (j < size - k - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (k + (ft_strlen(src)));
}
