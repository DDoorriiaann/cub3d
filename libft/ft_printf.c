/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:08:16 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/05/03 09:04:13 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_type(const char c, va_list params);

int	ft_printf(const char *format, ...)
{
	int		i;
	int		size;
	va_list	params;

	i = 0;
	size = 0;
	va_start(params, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			size += ft_type(format[i + 1], params);
			i += 2;
		}
		else
		{
			size += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(params);
	return (size);
}

static int	ft_type(const char c, va_list params)
{
	if (c == 'c')
		return (ft_putchar(va_arg(params, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(params, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(params, int)));
	else if (c == 'p')
		return (ft_putptr(va_arg(params, unsigned long long)));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(params, unsigned int)));
	else if (c == 'x')
		return (ft_puthexa_low(va_arg(params, unsigned int)));
	else if (c == 'X')
		return (ft_puthexa_upp(va_arg(params, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}
