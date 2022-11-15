/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:50:04 by mramiro-          #+#    #+#             */
/*   Updated: 2022/11/15 10:59:54 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	searchn(char *str)
{
	int	i;

	i = 0;
	while (str[i++] != '\0')
		if (str[i] == '\n')
			return (i);
	return (0);
}

char *copiarenout(char *buffer)
{
	int i;
	static char *out;
	static int size;
	static int n;

	size += BUFFER_SIZE;
	i = 0;
	n = 0;
	out = malloc(size);
	while (i < BUFFER_SIZE && buffer[i] != '\n')
	{
		out[n] = buffer[i];
		i++;
		n++;
	}
	return (out);
}

char *readdoc(int fd)
{
	char	*out;
	char	*buffer;
	int		bytenum;

	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (0);
	bytenum = read(fd, buffer, BUFFER_SIZE);
	if (!bytenum)
		return (-1);
	if (searchn(buffer) == 0)
	{
		out = copiarenout(buffer);
		while (searchn(buffer) == 0)
		{
			read(fd, buffer, BUFFER_SIZE);
			free(out);
			out = copiarenout(buffer);
		}
		readdoc(fd);
	}
	else
	{
		out = copiarenout(buffer);
	}
	free(buffer);
	return (out);
}

char *get_next_line(int fd)
{
	char *out;

	out = readdoc(fd);
	return (out);
}

int main()
{
	int fd = open("archivo.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	//printf("%d",buscarn("Hola \nBuenas"));
 }