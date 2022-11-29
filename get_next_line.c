/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:50:04 by mramiro-          #+#    #+#             */
/*   Updated: 2022/11/29 12:55:51 by mramiro-         ###   ########.fr       */
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

char	*readdoc(char *buffer, int fd)
{
	char	*out;
	char	*temp;
	int		numbytes;

	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (0);
	numbytes = read(fd, buffer, BUFFER_SIZE);
	if (numbytes == -1)
		return (0);
	out = copiarenout(buffer);
	while (searchn(buffer) == 0)
	{
		numbytes = read(fd, buffer, BUFFER_SIZE);
		printf("%s\n", buffer);
		temp = ft_strjoin(out, buffer);
		out = ft_strdup(temp);
		free(temp);
	}
	free(buffer);
	return (out);
}
//char* updateOut(int fd, char *buffer)
//{
//	int size;
//	static char *out;
//
//	size = ft_strlen(buffer);
//	read(fd, out + size, BUFFER_SIZE);
//	return (out);
//}
char	*get_next_line(int fd)
{
	static char	*out;
	char *temp;

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
	temp = readdoc(out, fd);
	read(fd, out, BUFFER_SIZE);
	printf("%s", out);
	return (temp);
}

int main()
{
	int fd = open("archivo.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	fd = open("archivo.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	//char *buffer = malloc(BUFFER_SIZE);
	//read(fd, buffer, BUFFER_SIZE);
	//printf("%s", buffer);
	//printf("%d",buscarn("Hola \nBuenas"));
	system("leaks -q a.out");
}