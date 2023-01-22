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
	return (0);
}

char	*readdoc(int fd)
{
	char	*out;
	char	*buffer;
	int		nbytes;

	nbytes = 1;
	out = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(1, sizeof(char));
	if (!out || !buffer)
		return (NULL);
	while (nbytes > 0 && searchn(out) == 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[nbytes] = '\0';
		out = ft_strjoin(out, buffer);
		if (searchn(buffer) != 0)
			break ;
	}
	free (buffer);
	return (out);
}

char	*getout(char *buffer)
{
	int		i;
	char	*out;

	i = 0;
	out = ft_calloc(searchn(buffer), sizeof(char));
	if (!out)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		out[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		out[i] = '\n';
	else
		out[i] = '\0';
	free (buffer);
	return (out);
}

char	*cutn(char *c)
{
	int		i;
	int		x;
	char	*out;

	i = searchn(c) + 1;
	x = ft_strlen(c) - i;
	out = ft_calloc(x + 1, sizeof(char));
	if (!out)
		return (NULL);
	x = 0;
	while (c[i] != '\0')
		out[x++] = c[i++];
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
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	out = readdoc(fd);
	if (temp != NULL)
		out = ft_strjoin(temp, out);
	temp = cutn(out);
	out = getout(out);
	return (out);
}

int main()
{
	int fd = open("archivo.txt", O_RDONLY);
	printf("Return: %s\n", get_next_line(fd));
	printf("Return: %s\n", get_next_line(fd));
	printf("Return: %s\n", get_next_line(fd));
	printf("Return: %s\n", get_next_line(fd));



	system("leaks -q a.out");
}
