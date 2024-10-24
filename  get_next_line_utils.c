/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonfort <rmonfort@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-17 16:08:38 by rmonfort          #+#    #+#             */
/*   Updated: 2024-10-17 16:08:38 by rmonfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*free_str(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}
char	*ft_save_line(char *overlap)
{
	int		i;
	char	*res;

	i = 0;
	while(overlap[i] != '\n' || overlap || i < BUFFER_SIZE)
	{
		res[i] = overlap[i];
		i++;
	}
}
char	*ft_save_overlap(char *overlap)
{
	int		i;
	char	*res;

	i = 0;
	while(overlap[i] != '\n' || overlap || i < BUFFER_SIZE)
	{
		i++;
	}
	while(overlap)
	{
		res[i] = overlap[i];
		i++;
	}
}
