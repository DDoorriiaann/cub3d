/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:57:04 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/14 13:08:09 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*tab;
	int		i;
	int		nbr;
	int		minus;

	minus = 1;
	i = 0;
	nbr = 0;
	tab = (char *) nptr;
	while ((tab[i] == ' ') || (tab[i] >= '\t' && tab[i] <= '\r'))
		i++;
	if (tab[i] == '-')
	{
		minus = minus * (-1);
		i++;
	}
	else if (tab[i] == '+')
		i++;
	while ((tab[i] != '\0') && (tab[i] >= '0') && (tab[i] <= '9'))
	{
		nbr = nbr * 10 + (tab[i] - '0');
		i++;
	}
	return (nbr * minus);
}
