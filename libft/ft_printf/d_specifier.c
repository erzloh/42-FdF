/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:40:58 by eholzer           #+#    #+#             */
/*   Updated: 2022/11/16 15:33:42 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Here are functions related to the %d specifier 

#include "ft_printf.h"

int	n_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	print_d(va_list args, int *len, int *i)
{
	int	d;

	d = va_arg(args, int);
	ft_putnbr_fd(d, 1);
	*len += n_len(d);
	(*i)++;
}
