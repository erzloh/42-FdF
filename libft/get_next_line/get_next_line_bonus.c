/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:43:58 by eholzer           #+#    #+#             */
/*   Updated: 2022/11/28 14:02:18 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Return 1 if it found an error, return 0 if not.
int	check_errors(int fd, char **reserve_ptr)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free(*reserve_ptr);
		*reserve_ptr = NULL;
		return (1);
	}
	return (0);
}

// Remove a line from the reserve.
void	update_reserve(char *reserve, char **reserve_ptr, int line_len)
{
	int		i;
	char	*new_reserve;

	i = 0;
	while (reserve[line_len + i])
		i++;
	new_reserve = malloc(sizeof(char) * (i + 1));
	ft_memcpy(new_reserve, reserve + line_len, i);
	new_reserve[i] = '\0';
	free(reserve);
	*reserve_ptr = new_reserve;
}

// Take the reserve and its address as arguments and return a line if a '\n' was
// found and remove the line from the reserve to keep only what is following the
// '\n'. Return NULL if no '\n' was found.
char	*get_trimmed_line(char *reserve, char **reserve_ptr)
{
	int		i;
	char	*line;

	i = 0;
	while (reserve[i])
	{
		if (reserve[i] == '\n')
		{
			line = malloc(sizeof(char) * (i + 1 + 1));
			if (!line)
				return (NULL);
			ft_memcpy(line, reserve, i + 1);
			line[i + 1] = '\0';
			update_reserve(reserve, reserve_ptr, i + 1);
			return (line);
		}
		i++;
	}
	return (NULL);
}

// Read a file and return a line if a newline is found.
char	*read_and_get_line(int fd, char **reserve_ptr)
{
	int		char_read;
	char	buf[BUFFER_SIZE + 1];
	char	*line;

	line = get_trimmed_line(*reserve_ptr, reserve_ptr);
	if (line)
		return (line);
	char_read = read(fd, buf, BUFFER_SIZE);
	while (char_read)
	{
		buf[char_read] = '\0';
		*reserve_ptr = ft_strjoin(*reserve_ptr, buf);
		line = get_trimmed_line(*reserve_ptr, reserve_ptr);
		if (line)
			return (line);
		if (char_read == BUFFER_SIZE)
			char_read = read(fd, buf, BUFFER_SIZE);
		else
		{
			line = *reserve_ptr;
			*reserve_ptr = NULL;
			return (line);
		}
	}
	return (NULL);
}

// The get_next_line function
char	*get_next_line(int fd)
{
	static char	*reserve[4096];
	char		*line;

	if (check_errors(fd, &reserve[fd]))
		return (NULL);
	if (!reserve[fd])
	{
		reserve[fd] = malloc(sizeof(char) * 1);
		if (!reserve[fd])
			return (NULL);
		*reserve[fd] = 0;
	}
	line = read_and_get_line(fd, &reserve[fd]);
	if (line)
		return (line);
	if (!*reserve[fd])
	{
		free(reserve[fd]);
		return (reserve[fd] = NULL);
	}
	line = reserve[fd];
	reserve[fd] = NULL;
	return (line);
}
