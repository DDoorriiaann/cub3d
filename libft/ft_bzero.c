/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:59:09 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 11:59:12 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char				*tab;
	long unsigned int	i;

	i = 0;
	tab = s;
	while (i < n)
	{
		tab[i] = '\0';
		i++;
	}
}
