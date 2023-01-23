/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_upp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:47:57 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/05/03 09:10:59 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_upp(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 15)
	{
		len += ft_puthexa_upp(nb / 16);
		len += ft_puthexa_upp(nb % 16);
	}
	else if (nb > 9)
		len += ft_putchar(nb + '7');
	else
		len += ft_putchar(nb + '0');
	return (len);
}
