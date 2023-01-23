/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:19:14 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 12:19:19 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;	
	char	*tab1;
	char	*tab2;
	size_t	j;
	size_t	k;

	j = 0;
	i = 0;
	tab1 = (char *) big;
	tab2 = (char *) little;
	if (tab2[i] == '\0')
		return (tab1);
	while ((i < len) && (tab1[i] != '\0'))
	{
		if (tab2[j] == tab1[i])
		{
			k = i;
			while (tab2[j++] == tab1[k++])
				if ((tab2[j] == '\0') && (k <= len))
					return (&tab1[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}
