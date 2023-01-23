/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:59:19 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 12:29:20 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if ((float)size * nmemb >= (float)18446744073709551615UL)
		return (NULL);
	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	while (i < nmemb * size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
