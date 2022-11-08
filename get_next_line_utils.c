/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:24:19 by mramiro-          #+#    #+#             */
/*   Updated: 2022/11/08 14:04:05 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Funcion que lea el documento anidando una lectura de cada linea
#include <unistd.h>

char *readDoc(int fd, size_t size)
{
	int i;
	char *c;

	c = malloc(size + 1);
	read(fd, c, size);
	allocateLines(fd, c);

}

int countCharLine(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\n')
	{
		i++;
	}
	return (i);
}


char *allocateLines(int fd, char *docContent)
{
	int i;
	static int size;
	char *result;

	size = 0;
	size += countCharLine(docContent + size);
	result = malloc(size);
	if (!result)
		return (0);
	read(fd, result, size);
	return (result);
}