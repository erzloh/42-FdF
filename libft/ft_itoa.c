/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:52:28 by eric              #+#    #+#             */
/*   Updated: 2022/12/14 10:33:15 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	power(int n, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	while (power--)
		res *= n;
	return (res);
}

static char	*is_exception(int n, char *str)
{
	if (n == 0)
	{
		str = malloc(sizeof(char) * 2);
		*str = '0';
		*(str + 1) = '\0';
		return (str);
	}
	if (n == -2147483648)
	{
		str = malloc(sizeof(char) * 12);
		ft_memcpy(str, "-2147483648", 11);
		str[11] = '\0';
		return (str);
	}
	return (NULL);
}

static char	*get_str_from_int(char *str, int n, int len)
{
	int		i;
	int		u;
	int		is_negative;

	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n *= -1;
	}
	i = 0;
	str = malloc(sizeof(char) * (len + is_negative + 1));
	if (!str)
		return (NULL);
	if (is_negative)
		str[i++] = '-';
	while (i < len + is_negative)
	{
		u = n / power(10, len - 1 - i + is_negative);
		str[i] = '0' + u;
		n = n - u * power(10, len - 1 - i + is_negative);
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	str = NULL;
	str = is_exception(n, str);
	if (str)
		return (str);
	len = nbr_len(n);
	str = get_str_from_int(str, n, len);
	return (str);
}
