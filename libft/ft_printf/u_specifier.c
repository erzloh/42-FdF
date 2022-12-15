/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:48:07 by eholzer           #+#    #+#             */
/*   Updated: 2022/11/16 15:33:54 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Here are functions related to the %u specifier 

#include "ft_printf.h"

void	ft_putnbr_fd_u(unsigned int n, int fd)
{
	if (n < 10)
	{
		ft_putchar_fd('0' + n, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + (n % 10), fd);
	}
}

int	n_len_u(unsigned int n)
{
	int	len;

	len = 0;
	if (!n)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	print_u(va_list args, int *len, int *i)
{
	unsigned int	u;

	u = va_arg(args, int);
	ft_putnbr_fd_u(u, 1);
	*len += n_len_u(u);
	(*i)++;
}
