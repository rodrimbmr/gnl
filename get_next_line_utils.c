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
	int		j;

	i = 0;
	while(overlap[i] != '\n' && overlap[i] != '\0')
	{
		i++;
	}
	j = 0;
	res = malloc(sizeof(char) * (i +1));
	if(!res)
		return (NULL);
	while(j < i)
	{
		res[j] = overlap[j];
		i++;
	}
	res[j] = '\0';
	return(res);

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
	if (overlap[start] == '\n')
		start++;
	len = ft_strlen(overlap + start);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return NULL;
	i = 0;
	while (overlap[start])
    res[i++] = overlap[start++];
	res[i] = '\0';
	return(res);
}
size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str++ != '\0')
	{
		count ++;
	}
	return (count);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rs;
	int		i;
	int		j;

	if (!s1)
		return ((char *)s2);
	rs = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!rs)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		rs[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
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
	while (s[i] != '\0')
	{
		if ((unsigned char)c == (unsigned char)s[i])
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
