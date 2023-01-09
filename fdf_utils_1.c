/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:11:06 by eholzer           #+#    #+#             */
/*   Updated: 2023/01/09 11:43:40 by eholzer          ###   ########.fr       */
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

void	print_map(t_map map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map.y_len)
	{
		i = 0;
		while (i < map.x_len)
		{
			printf("%d ", map.tab_2d[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
	printf("x_len = %d\n", map.x_len);
	printf("y_len = %d\n", map.y_len);
}
