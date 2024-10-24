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

static	*read_line(int fd, char **overlap, char **buffer)
{
	char		*tmp;
	ssize_t		bytes_read;

	bytes_read = 1; // Truquito para el while (futuro)
	while (!(ft_strchar(overlap, '\n')) && bytes_read >= 1)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_str(overlap), free_str(buffer), NULL);
		else if (bytes_read > 0)
		{
			*buffer[bytes_read] = '\0';
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

	// Inicialización del buffer;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';

	if (read_line(fd, &overlap, &buffer) == NULL)
		return (NULL);
	buffer = ft_save_line(overlap);
	overlap = ft_save_overlap(overlap);
	// TODO
	return (buffer);
}

