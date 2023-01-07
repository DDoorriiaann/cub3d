/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:25:04 by dguet             #+#    #+#             */
/*   Updated: 2022/04/11 18:41:12 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s2;
	unsigned int	i;

	if (!s)
		return (NULL);
	s2 = malloc(sizeof (char) * (ft_strlen(s) + 1));
	if (!s2)
		return (NULL);
	i = -1;
	while (s[++i])
		s2[i] = (*f)(i, s[i]);
	s2[i] = '\0';
	return (s2);
}
