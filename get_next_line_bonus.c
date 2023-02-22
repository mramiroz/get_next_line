/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:15:14 by mramiro-          #+#    #+#             */
/*   Updated: 2023/02/22 07:34:36 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	searchn(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*readdoc(char *buffer, int fd)
{
	char	*tmp;
	int		numbytes;

	if (buffer == NULL)
		buffer = ft_calloc(1, sizeof(char));
	numbytes = 1;
	tmp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!tmp)
		return (NULL);
	while (0 < numbytes)
	{
		numbytes = read(fd, tmp, BUFFER_SIZE);
		if (numbytes == -1)
		{
			free (tmp);
			return (NULL);
		}
		tmp[numbytes] = '\0';
		buffer = ft_join(buffer, tmp);
		if (searchn(buffer) > -1)
			break ;
	}
	free (tmp);
	return (buffer);
}

static char	*cutn(char *c)
{
	int		i;
	int		x;
	char	*out;

	i = 0;
	while (c[i] && c[i] != '\n')
		i++;
	if (!c[i])
	{
		free(c);
		return (NULL);
	}
	if (c[i] == '\n')
		i++;
	x = ft_strlen(c) - i;
	out = ft_calloc(x + 1, sizeof(char));
	if (!out)
		return (NULL);
	x = 0;
	while (c[i] != '\0')
		out[x++] = c[i++];
	free (c);
	return (out);
}

char	*get_next_line(int fd)
{
	char		*out;
	static char	*temp[1024];

	if (read(fd, 0, 0) < 0)
	{
		if (temp[fd] != NULL)
		{
			free (temp[fd]);
			temp[fd] = NULL;
		}
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp[fd] = readdoc(temp[fd], fd);
	if (ft_strlen(temp[fd]) == 0)
	{
		free (temp[fd]);
		temp[fd] = NULL;
		return (NULL);
	}
	out = ft_strdup(temp[fd]);
	temp[fd] = cutn(temp[fd]);
	return (out);
}
