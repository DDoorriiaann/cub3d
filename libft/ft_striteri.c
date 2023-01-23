/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:08:35 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 12:23:12 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	index;

	index = 0;
	if ((s == NULL) || (f == NULL))
		return ;
	while (s[index] != '\0')
	{
		(*f)(index, &s[index]);
		index++;
	}
}
