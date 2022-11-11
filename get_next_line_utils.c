/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:24:19 by mramiro-          #+#    #+#             */
/*   Updated: 2022/11/11 15:26:03 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//char	*readdoc(int fd, size_t size)
//{
//	char	*c;
//	int		i;
//
//	i = 0;
//	c = malloc(size);
//	if (!c)
//		return (0);
//	read(fd, c, size);
//	allocatelines(fd, c);
//	free(fd);
//	return (c);
//}
//
//int	countcharline(char *line)
//{
//	int	i;
//
//	i = 0;
//	while (line[i] != '\n')
//	{
//		i++;
//	}
//	return (i);
//}
//
//char	*allocatelines(int fd, char *docContent)
//{
//	static int 	size;
//	char		*result;
//	int			i;
//
//	i = 0;
//	size += countcharline(docContent + size);
//	result = malloc(size);
//	if (!result)
//		return (0);
//	read(fd, result, size);
//	return (result);
//}

char	*readdoc(int fd, size_t size)
{
	char	*c;
	int		i;
	int		n;
	char	*result;

	i = 0;
	c = malloc(c);
	if (!c)
		return (0);
	read(fd, c, size);
	while (c[i] != '\0')
	{
		n += (int)size;
		read(fd, c + n, size);
		result = malloc(n);
		i++;
	}
	return (c);
}

int	validarn(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
