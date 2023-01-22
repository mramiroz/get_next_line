#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif
    int	ft_strlen(const char *str);
    void	*ft_calloc(size_t num, size_t size);
    char	*ft_strjoin(char const *s1, char const *s2);
    char	*ft_strdup(const char *s);
    int searchn(char *c);
    char *readdoc(int fd, char *buffer);
    char *getout(char *buffer);
    char *cutn(char *c);
    char *get_next_line(int fd);
#endif