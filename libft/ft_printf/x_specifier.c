/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:49:33 by eholzer           #+#    #+#             */
/*   Updated: 2022/11/16 13:52:14 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Get a hex char from a decimal number
// e.g. 1 -> '1', ..., 10 -> 'A', 11 -> 'B', etc...
// if we want the letters abcdef from the hex number to be uppercase
// then uppercase = something else than 0
char	get_hexchar(int n, char uppercase)
{
	int	interval;

	interval = 0;
	if (uppercase)
		interval = 'a' - 'A';
	if (n == 10)
		return ('a' - interval);
	else if (n == 11)
		return ('b' - interval);
	else if (n == 12)
		return ('c' - interval);
	else if (n == 13)
		return ('d' - interval);
	else if (n == 14)
		return ('e' - interval);
	else if (n == 15)
		return ('f' - interval);
	else
		return ('0' + n);
}

// Print an integer in hexadecimal
void	putnbr_hex(unsigned int n, char uppercase)
{
	if (n / 16 != 0)
	{
		putnbr_hex(n / 16, uppercase);
		ft_putchar_fd(get_hexchar(n % 16, uppercase), 1);
	}
	else
	{
		ft_putchar_fd(get_hexchar(n, uppercase), 1);
	}
}

// Get the length of a hexadecimal number from an unsigned int
int	get_hexlen(unsigned int n)
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

void	print_x(va_list args, int *len, int *i, char uppercase)
{
	int	x;

	x = va_arg(args, int);
	putnbr_hex(x, uppercase);
	*len += get_hexlen(x);
	(*i)++;
}
