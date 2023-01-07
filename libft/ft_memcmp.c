/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:58:42 by dguet             #+#    #+#             */
/*   Updated: 2022/04/05 18:48:15 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1b;
	unsigned char	*s2b;
	size_t			i;

	s1b = (unsigned char *)s1;
	s2b = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1b[i] == s2b[i] && i < n - 1)
	{	
		i++;
	}
	return (s1b[i] - s2b[i]);
}
