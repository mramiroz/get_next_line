/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:24:19 by mramiro-          #+#    #+#             */
/*   Updated: 2022/11/29 09:32:08 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
	{
		dest[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		dest[i] = '\n';
	else
		dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*s;

	if (!s1 || !s2)
		return (0);
	i = 0;
	len1 = ft_strlen(s1);
	if(searchn(s2) != 0)
		len2 = searchn(s2);
	else
		len2 = ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s)
		return (0);
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	i = -1;
	while (s2[++i])
		s[len1++] = s2[i];
	s[len1] = '\0';
	free(s1);
	return (s);
}
