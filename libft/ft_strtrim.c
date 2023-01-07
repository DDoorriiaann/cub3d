/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:46:24 by dguet             #+#    #+#             */
/*   Updated: 2022/04/12 22:29:02 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[len]) && len > i)
		len --;
	str = ft_substr(s1, i, (len - i) + 1);
	if (!str)
		return (NULL);
	return (str);
}
