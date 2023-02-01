/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrarmiro- <mramiro-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:39:02 by mrarmiro-         #+#    #+#             */
/*   Updated: 2023/01/17 16:39:02 by mrarmiro-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

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

void	*ft_calloc(size_t num, size_t size)
{
	char	*s;
	int		len;
	int		i;

	i = 0;
	len = num * size;
	s = malloc (len);
	if (!s || (len && (len / size != num)))
		return (0);
	while (i < len)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
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
	len2 = ft_strlen(s2);
	s = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!s)
		return (0);
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	i = -1;
	while (s2[++i])
		s[len1++] = s2[i];
	return (s);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s);
	dest = (char *)ft_calloc(size + 1, sizeof(char));
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

char	*ft_join(char *s1, char *s2)
{
	char	*aux;

	aux = ft_strjoin(s1, s2);
	if (!aux)
		return (NULL);
	free (s1);
	return (aux);
}
