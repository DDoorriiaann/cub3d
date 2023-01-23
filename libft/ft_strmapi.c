/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:31:10 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/11 16:11:56 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	index;
	char			*str;

	if ((s == NULL) || (f == NULL))
		return (NULL);
	index = 0;
	len = ft_strlen(s);
	str = malloc((sizeof(char) * (len + 1)));
	if (!str)
		return (0);
	str[len] = '\0';
	while (s[index] != '\0' )
	{	
		str[index] = (*f)(index, s[index]);
		index++;
	}
	return (str);
}
