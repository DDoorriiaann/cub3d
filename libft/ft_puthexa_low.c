/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_low.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:08:07 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/05/03 09:10:15 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_low(unsigned long long nb)
{
	int	len;

	len = 0;
	if (nb > 15)
	{
		len += ft_puthexa_low(nb / 16);
		len += ft_puthexa_low(nb % 16);
	}
	else if (nb > 9)
		len += ft_putchar(nb + 'W');
	else
		len += ft_putchar(nb + '0');
	return (len);
}
