/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:45:15 by dguet             #+#    #+#             */
/*   Updated: 2022/04/11 18:39:51 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

static unsigned int	ft_nblen(int n)
{
	unsigned int	i;
	long int		nbr;

	i = 0;
	nbr = n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nbr = -nbr;
		i++;
	}
	while ((unsigned int)n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	i;
	long int		nbr;

	i = ft_nblen(n);
	nbr = n;
	s = malloc (sizeof (char) * (i + 1));
	if (!s)
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
		s[0] = '-';
	}	
	s[i] = '\0';
	if (nbr == 0)
		s[0] = '0';
	while (nbr > 0)
	{
		i--;
		s[i] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (s);
}
