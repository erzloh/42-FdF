/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:52:58 by eholzer           #+#    #+#             */
/*   Updated: 2022/11/16 13:54:03 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr_hex_p(unsigned long int n, char uppercase)
{
	if (n / 16 != 0)
	{
		putnbr_hex_p(n / 16, uppercase);
		ft_putchar_fd(get_hexchar(n % 16, uppercase), 1);
	}
	else
	{
		ft_putchar_fd(get_hexchar(n, uppercase), 1);
	}
}

int	get_hexlen_p(unsigned long int n)
{
	int	len;

	len = 0;
	if (!n)
		len = 1;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	print_p(va_list args, int *len, int *i)
{
	unsigned long int	p;

	p = va_arg(args, unsigned long int);
	ft_putstr_fd("0x", 1);
	*len += 2;
	putnbr_hex_p(p, 0);
	*len += get_hexlen_p(p);
	(*i)++;
}
