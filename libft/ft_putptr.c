/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:12:01 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/05/03 09:14:41 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_puthexa_low(nb);
	return (len);
}
