/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:51:18 by dguet             #+#    #+#             */
/*   Updated: 2022/04/05 19:01:48 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen (s) + 1;
	while (--len > -1)
		if (s[len] == (unsigned char)c)
			return ((char *)&s[len]);
	return (NULL);
}
