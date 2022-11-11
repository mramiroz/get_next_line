/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:24:19 by mramiro-          #+#    #+#             */
/*   Updated: 2022/11/11 18:56:15 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readdoc(int fd, char *buffer, size_t size)
{
	int i;
	char *out;
	static int len;

	i = 0;
	len = 0;
	if (buscarn(buffer) == 0)
	{
		out = malloc(len);
		if (!out)
			return (0);
		out = getline(out, buffer + len);
		free(out);
		len += size;
	}
	else
	{
		len = buscarn(buffer);
	}
}

char *getline(char *out, char *buffer)
{
	int i;

	i = 0;
	while (buffer[i] != '\n')
	{
		out[i] = buffer[i];
		i++;
	}
	return (out);
}

int	buscarn(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
			return (i);
		i++;
	}
	return (0);
}
