#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*copy(char *src, int start, int end);
int		find_line_end(char *s, int size);
char	*append(char *line, char *buf, int num_chars);

#endif
