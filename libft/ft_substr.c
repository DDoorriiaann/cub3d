/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:39:10 by dguet             #+#    #+#             */
/*   Updated: 2022/04/12 22:26:44 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				i;
	char			*sub;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen (s);
	i = ft_strlen(s) - start;
	if ((unsigned int)start > s_len)
		return (ft_strdup(""));
	if (len > (unsigned int)i)
		len = i;
	sub = malloc (sizeof (char) * len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
