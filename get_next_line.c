/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:50:04 by mramiro-          #+#    #+#             */
/*   Updated: 2022/12/14 18:35:29 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	searchn(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*copiarenout(char *buffer)
{
	int i;
	char *out;

	out = malloc(searchn(buffer));
	i = 0;
	while (buffer[i] != '\n')
	{
		out[i] = buffer[i];
		i++;
	}
	return (out);
}

char	*readdoc(char *buffer, int fd)
{
	char	*out;
	int		numbytes;

	// printf("BUFF -> %s\n", buffer);
	buffer = malloc(BUFFER_SIZE);
	numbytes = read(fd, buffer, BUFFER_SIZE);
	if (numbytes == -1)
		return (0);
	out = ft_strdup(buffer);
	while (searchn(buffer) == 0 && searchn(out) == 0)
	{
		read(fd, buffer, BUFFER_SIZE);
		out = ft_strjoin(out, buffer);
	}
	free(buffer);
	return (out);
}

static char *saverest(char *buffer)
{
	int c;
	int i;
	static char *out;

	c = searchn(buffer) + 1;	
	i = 0;
	out = malloc(ft_strlen(buffer) - c);
	while (i < ft_strlen(out))
	{
		out[i] = buffer[c];
		i++;
		c++;
	}
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
			free(temp);
			temp = NULL;
		}
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	out = readdoc(temp, fd);
	printf("Read: %s\n", out);
	temp = saverest(out);
	printf("Save: %s\n", temp);
	out = copiarenout(out);
	return (out);
}

int main()
{
	int fd = open("archivo.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));

	//system("leaks -q a.out");
}