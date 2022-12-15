/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:44:01 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/14 10:20:14 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft.h"

int		ft_printf(const char *format, ...);
int		get_arg_nb(const char *str);

// functions related to the %d specifier
int		n_len(int n);
void	print_d(va_list args, int *len, int *i);

// functions related to the %u specifier
void	ft_putnbr_fd_u(unsigned int n, int fd);
int		n_len_u(unsigned int n);
void	print_u(va_list args, int *len, int *i);

// functions related to the %x specifier
char	get_hexchar(int n, char uppercase);
void	putnbr_hex(unsigned int n, char uppercase);
int		get_hexlen(unsigned int n);
void	print_x(va_list args, int *len, int *i, char uppercase);

// functions related to the %p specifier
void	putnbr_hex_p(unsigned long int n, char uppercase);
int		get_hexlen_p(unsigned long int n);
void	print_p(va_list args, int *len, int *i);

// Others
void	print_c(va_list args, int *len, int *i);
void	print_percent(int *len, int *i);
void	check_specifiers(const char *format, va_list args, int *len, int *i);
#endif
