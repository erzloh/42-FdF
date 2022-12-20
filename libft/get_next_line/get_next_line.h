/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:44:27 by eholzer           #+#    #+#             */
/*   Updated: 2022/11/28 10:47:41 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// Functions from the Libft
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

// Utility functions
int		check_errors(int fd, char **reserve_ptr);
char	*read_and_get_line(int fd, char **reserve_ptr);
char	*get_trimmed_line(char *reserve, char **ptr_reserve);

// The actual get_next_line function
char	*get_next_line(int fd);

#endif