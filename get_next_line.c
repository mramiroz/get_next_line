/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:50:04 by mramiro-          #+#    #+#             */
/*   Updated: 2022/11/29 10:26:35 by mramiro-         ###   ########.fr       */
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
	int				i;
	char			*out;
	int 	size;
	int				n;
	
	size = 0;
	size += BUFFER_SIZE;
	i = 0;
	n = 0;
	out = malloc(size);
	if(!out)
		return(0);
	while (i < BUFFER_SIZE && buffer[i] != '\n')
		out[n++] = buffer[i++];
	if (buffer[i] == '\n')
		out[n] = '\n';
	else if (buffer[i] == '\0')
		out[n] = '\0';
	return (out);
}

char	*readdoc(char *out, int fd)
{
	char	*buffer;
	char	*temp;
	int		numbytes;

	buffer = malloc(BUFFER_SIZE);
	numbytes = read(fd, buffer, BUFFER_SIZE);
	if (searchn(buffer) != 0)
	{
		out = copiarenout(buffer);
		free(buffer);
		return (out);
	}
	out = copiarenout(buffer);
	while (searchn(buffer) == 0 && searchn(out) == 0)
	{
		read(fd, buffer, BUFFER_SIZE);
		temp = ft_strjoin(out, buffer);
		out = ft_strdup(temp);
		free(temp);
	}
	free(buffer);
	return (out);
}

char	*get_next_line(int fd)
{
	static char	*out;

	if (read(fd, 0, 0) < 0)
	{
		if (out != NULL)
		{
			free(out);
			out = NULL;
		}
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	out = readdoc(out, fd);
	if (!out)
		return (0);
	return (out);
}

int main()
{
	int fd = open("archivo.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	//char *buffer = malloc(BUFFER_SIZE);
	//read(fd, buffer, BUFFER_SIZE);
	//printf("%s", buffer);
	//printf("%d",buscarn("Hola \nBuenas"));
	system("leaks -q a.out");
}