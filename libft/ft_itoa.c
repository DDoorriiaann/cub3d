/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:45:25 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/04/11 09:45:39 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	size_t		len;
	long int	nbr;

	nbr = n;
	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = (nbr * -1);
		len++;
	}
	while (nbr > 0)
	{	
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long int	nbr;

	len = ft_len(n);
	nbr = n;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		(str[0] = '-');
		nbr = nbr * -1;
	}
	--len;
	while (nbr > 0)
	{
		str[len--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}
