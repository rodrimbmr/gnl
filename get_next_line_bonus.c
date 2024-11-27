/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonfort <rmonfort@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-20 16:31:48 by rmonfort          #+#    #+#             */
/*   Updated: 2024-10-20 16:31:48 by rmonfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#define MAX_FD 1024

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str && *str++ != '\0')
		count ++;
	return (count);
}

static char	*read_line(int fd, char **overlap, char **buffer)
{
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(*overlap, '\n') == NULL)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_str(overlap), free_str(buffer), NULL);
		if (bytes_read > 0)
		{
			(*buffer)[bytes_read] = '\0';
			tmp = ft_strjoin(*overlap, *buffer);
			free_str(overlap);
			if (!tmp)
				return (free_str(&tmp), free_str(buffer), NULL);
			*overlap = tmp;
		}
	}
	return (*overlap);
}

char	*get_next_line(int fd)
{
	static char	*overlap[MAX_FD];
	char		*buffer;
	char		*line;
	char		*noverlap;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_str(&overlap[fd]), NULL);
	buffer[BUFFER_SIZE] = '\0';
	if (read_line(fd, &overlap[fd], &buffer) == NULL)
		return (free_str(&overlap[fd]), free_str(&buffer), NULL);
	free_str(&buffer);
	line = ft_save_line(&overlap[fd]);
	if (!overlap[fd])
		return (NULL);
	noverlap = ft_save_overlap(overlap[fd]);
	free_str(&overlap[fd]);
	overlap[fd] = noverlap;
	return (line);
}
