/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:11:06 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/17 11:19:58 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Return absolute value of an integer
int	abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

// Return absolute value of a float
float	f_abs(float n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

// Swap the value of two variables
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
