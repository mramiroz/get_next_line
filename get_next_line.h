/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrarmiro- <mramiro-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:23:36 by mramiro-          #+#    #+#             */
/*   Updated: 2022/11/15 18:41:17 by mrarmiro-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_strjoin(char const *s1, char const *s2);
int     ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char *get_next_line(int fd);
char *readdoc(int fd);
char *copiarenout(char *buffer);
int	searchn(char *str);
char	*ft_strdup(const char *s);




#endif