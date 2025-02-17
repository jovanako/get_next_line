#include "get_next_line.h"

static void	*clean_up(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

static int	fill_line_buf(char **line_buf, char *read_buf, int fd)
{
	int	bytes_read;

	bytes_read = 0;
	while (find_new_line(*line_buf) < 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (1);
		if (bytes_read == 0)
			break ;
		append(line_buf, read_buf, bytes_read);
		if (*line_buf == NULL)
			return (1);
	}
	return (0);
}

static char	*cut_line(char **line_buf, int nl_i)
{
	char	*line;
	char	*rest;
	int		line_buf_len;

	rest = NULL;
	line_buf_len = ft_strlen(*line_buf);
	if (nl_i > -1 && nl_i != (line_buf_len - 1))
	{
		line = ft_substr(line_buf, 0, nl_i + 1);
		if (line == NULL)
			return (NULL);
		rest = ft_substr(line_buf, nl_i + 1, line_buf_len - (nl_i + 1));
		if (rest == NULL)
		{
			free(line);
			line = NULL;
		}
		free(*line_buf);
	}
	else
		line = *line_buf;
	*line_buf = rest;
	return (line);
}

static char	*ft_get_line(char **line_buf)
{
	int	nl_i;

	if (ft_strlen(*line_buf) == 0)
		return (clean_up(line_buf));
	nl_i = find_new_line(*line_buf);
	return (cut_line(line_buf, nl_i));
}

char	*get_next_line(int fd)
{
	static char	*line_buf;
	char		*read_buf;

	if (line_buf == NULL)
	{
		line_buf = malloc(1 * sizeof(char));
		if (line_buf == NULL)
			return (NULL);
		line_buf[0] = '\0';
	}
	read_buf = malloc(BUFFER_SIZE * sizeof(char));
	if (read_buf == NULL)
		return (clean_up(&line_buf));
	if (fill_line_buf(&line_buf, read_buf, fd))
	{
		free(read_buf);
		return (clean_up(&line_buf));
	}
	free(read_buf);
	return (ft_get_line(&line_buf));
}
