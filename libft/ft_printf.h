/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybaudoui <ybaudoui@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:09:36 by ybaudoui          #+#    #+#             */
/*   Updated: 2022/05/03 10:15:44 by ybaudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int	ft_putchar(const char c);
int	ft_putstr(const char *str);
int	ft_putnbr(int nb);
int	ft_printf(const char*format, ...);
int	ft_putnbr_u(unsigned int nb);
int	ft_puthexa_low(unsigned long long nb);
int	ft_puthexa_upp(unsigned int nb);
int	ft_putptr(unsigned long long nb);

#endif
