#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		find_new_line(char *s);
int		ft_strlen(char *str);
void	append(char **line_buf, char *read_buf, int bytes_read);
char	*ft_substr(char **s, int start, int len);

#endif
