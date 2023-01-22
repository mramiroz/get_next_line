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

int searchn(char *c)
{
    int i;

    i = 0;
    while(c[i] != '\0')
    {
        if(c[i] == '\n')
            return(i);
        i++;
    }
    return (0);
}

char *readdoc(int fd, char *buffer)
{
    char *out;
    int nbytes;

    if (!buffer)
        buffer = ft_calloc(1, sizeof(char));
    nbytes = 1;
    out = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if (!out)
        return(NULL);
    while(nbytes > 0)
    {
        nbytes = read(fd, out, BUFFER_SIZE);
        if (nbytes == 0)
        {
            free(buffer);
            return (NULL);
        }
        out[nbytes] == '\0';
        buffer = ft_strjoin(buffer, out);
        if (searchn(buffer) > 0)
            break;
    }
    free(out);
    return (buffer);
}

char *getout(char *buffer)
{
    int i;
    char *out;

    i = 0;
    out = ft_calloc(searchn(buffer), sizeof(char));
    if (!out)
        return (NULL);
    while (buffer[i] != '\n' && buffer[i] != '\0')
    {
        out[i] = buffer[i];
        i++;
    }
    out[i] = '\0';
    free(buffer);
    return (out);

}

char *cutn(char *c)
{
    int i;
    int count;
    char *out;

    i = 0;
    count = 0;
    while (c[count] && c[count] != '\n')
        count++;
    if (!c[count])
    {
        free(c);
        return (NULL);
    }
    if (c[count] == '\n')
        count++;
    out = ft_calloc((ft_strlen(c) - count) + 1, sizeof(char));
    if (!out)
        return (NULL);
    while(c[i] != '\0')
        out[count++] = c[i++];
    return (out);
}

char *get_next_line(int fd)
{
    char *out;
    static char *temp;

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
    temp = readdoc(fd, temp);
    if (!temp)
        return (NULL);
    out = ft_strdup(temp);
    temp = cutn(temp);
    return (out);
}


/*
int main()
{
	int fd = open("archivo.txt", O_RDONLY);
	printf("Return: %s\n", get_next_line(fd));
	printf("Return: %s\n", get_next_line(fd));
	printf("Return: %s\n", get_next_line(fd));
	printf("Return: %s\n", get_next_line(fd));



	system("leaks -q a.out");
}
*/
