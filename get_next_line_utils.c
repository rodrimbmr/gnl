/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonfort <rmonfort@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-17 16:08:38 by rmonfort          #+#    #+#             */
/*   Updated: 2024-10-17 16:08:38 by rmonfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

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
	int		j;

	if (overlap[0] == '\0')
		return (NULL);
	i = 0;
	while (overlap[i] != '\n' && overlap[i] != '\0')
		i++;
	if (overlap[i] == '\n')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (j < i)
	{
		res[j] = overlap[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_save_overlap(char *overlap)
{
	int		start;
	int		len;
	int		i;
	char	*res;

	start = 0;
	while (overlap[start] != '\n' && overlap[start] != '\0')
		start++;
	if (overlap[start] == '\0')
		return (NULL);
	start++;
	len = ft_strlen(overlap + start);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (overlap[start] != '\0')
	{
		res[i] = overlap[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rs;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	rs = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!rs)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		rs[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		rs[i] = s2[j];
		i++;
		j++;
	}
	rs[i] = '\0';
	return (rs);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if ((unsigned char)c == (unsigned char)s[i])
			return ((char *)&s[i]);
		i++;
	}
	if (s && (unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
