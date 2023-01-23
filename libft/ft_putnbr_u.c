/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:19:41 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/05/03 09:14:07 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putchar((nb % 10) + '0');
	}
	else
	{
		len += ft_putchar(nb + '0');
	}
	return (len);
}
