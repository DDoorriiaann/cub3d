/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:22:40 by dguet             #+#    #+#             */
/*   Updated: 2022/04/04 21:05:44 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	add_len;
	char	*s;
	char	*d;

	s = (char *)src;
	d = dst;
	add_len = size;
	while (add_len-- != 0 && *d != '\0')
		d++;
	dst_len = d - dst;
	add_len = size - dst_len;
	if (add_len == 0)
		return (dst_len + ft_strlen(s));
	while (*s)
	{
		if (add_len != 1)
		{
			*d++ = *s;
			add_len--;
		}
		s++;
	}
	*d = '\0';
	return (dst_len + (s - src));
}
