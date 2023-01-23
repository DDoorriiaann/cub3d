/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:19:50 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 12:19:52 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*str;
	int	t;

	if (s == 0)
		return (0);
	if (start > ft_strlen(s))
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	if ((len + start) <= ft_strlen(s))
		t = len;
	else if ((len + start) > ft_strlen(s))
		t = (ft_strlen(s) - start);
	else
		t = 1;
	str = malloc(sizeof(char) * (t + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[start], t + 1);
	return (str);
}
