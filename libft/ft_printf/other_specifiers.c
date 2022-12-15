/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_s_percent_specifier.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:54:41 by eholzer           #+#    #+#             */
/*   Updated: 2022/11/16 13:56:15 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(va_list args, int *len, int *i)
{
	ft_putchar_fd(va_arg(args, int), 1);
	(*len)++;
	(*i)++;
}

void	print_s(va_list args, int *len, int *i)
{
	char	*s;

	s = va_arg(args, char *);
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		*len += 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		*len += ft_strlen(s);
	}
	(*i)++;
}

void	print_percent(int *len, int *i)
{
	ft_putchar_fd('%', 1);
	(*len)++;
	(*i)++;
}

void	check_specifiers(const char *format, va_list args, int *len, int *i)
{
	if (format[*i + 1] == 'c')
		print_c(args, len, i);
	else if (format[*i + 1] == 's')
		print_s(args, len, i);
	else if (format[*i + 1] == 'p')
		print_p(args, len, i);
	else if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
		print_d(args, len, i);
	else if (format[*i + 1] == 'u')
		print_u(args, len, i);
	else if (format[*i + 1] == 'x')
		print_x(args, len, i, 0);
	else if (format[*i + 1] == 'X')
		print_x(args, len, i, 1);
	else if (format[*i + 1] == '%')
		print_percent(len, i);
}
