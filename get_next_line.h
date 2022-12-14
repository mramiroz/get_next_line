/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:23:36 by mramiro-          #+#    #+#             */
/*   Updated: 2022/12/14 17:58:20 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char	*ft_strjoin(char *s1, char *s2);
int     ft_strlen(const char *str);
char 	*get_next_line(int fd);
char 	*readdoc(char *out, int fd);
char 	*copiarenout(char *buffer);
int		searchn(const char *str);
char	*ft_strdup(const char *s);

#endif