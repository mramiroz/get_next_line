/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrarmiro- <mramiro-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:40:12 by mrarmiro-         #+#    #+#             */
/*   Updated: 2023/01/17 16:40:12 by mrarmiro-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*temp;

	if (read(fd, 0, 0) < 0)
	{
		if (temp != NULL)
		{
			free (temp);
			temp = NULL;
		}
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = readdoc(temp, fd);
	if (ft_strlen(temp) == 0)
	{
		if(temp != NULL)
		{
			free (temp);
			temp =  NULL;
		}
		return (NULL);
	}
	out = ft_strdup(temp);
	temp = cutn(temp);
	return (out);
}
/*
int main()
{
	int fd = open("archivo.txt", O_RDONLY);
	printf("R: %s", get_next_line(fd));
	printf("R: %s", get_next_line(fd));
	//printf("R: %s", get_next_line(fd));
	//printf("R: %s", get_next_line(fd));
	//printf("R: %s", get_next_line(fd));

	system("leaks -q a.out");
}
*/