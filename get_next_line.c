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

#include "get_next_line.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

static char	*read_line(int fd,char **overlap , char **buffer)
{
	char		*tmp;
	int		bytes_read;

	bytes_read = 1; // Truquito para el while (futuro)
	while (bytes_read >= 1)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_str(overlap), free_str(buffer), NULL);
		else if (bytes_read > 0)
		{
			(*buffer)[bytes_read] = '\0';
			tmp = ft_strjoin(*overlap, *buffer);
			if (!tmp)
				return (free_str(overlap), free_str(buffer), NULL);
			free_str(overlap);
			*overlap = tmp;
		}
	}
	return (*overlap);
}

char	*get_next_line(int fd)
{
	static char	*overlap;
	char		*buffer;
	char		*line;
	char		*noverlap;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';

	if (read_line(fd,&overlap , &buffer) == NULL)
	{
		free_str(&buffer);
		return (NULL);
	}
	free_str(&buffer);
	line = ft_save_line(overlap);
	noverlap = ft_save_overlap(overlap);
	free_str(&overlap);
	overlap = noverlap;
	return (line);
}

