/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:41:18 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/05/03 09:15:17 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
	{	
		write(1, "(null)", 6);
		return (6);
	}
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
		len++;
	}
	return (len);
}
