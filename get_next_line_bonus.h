/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 07:32:25 by mramiro-          #+#    #+#             */
/*   Updated: 2023/02/22 07:32:52 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 50

# endif

int		ft_strlen(const char *str);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strjoin(char *s1, char *s2);
int		searchn(char *c);
char	*get_next_line(int fd);
char	*ft_join(char *s1, char *s2);
char	*ft_strdup(char *s);

#endif