#include "get_next_line.h"

static char	*rest_to_read(char *rest_buf, char *read_buf, int *bytes_read)
{
	char	*result;

	*bytes_read = 0;
	if (*rest_buf)
	{
		while (rest_buf[*bytes_read])
		{
			read_buf[*bytes_read] = rest_buf[*bytes_read];
			(*bytes_read)++;
		}
		free(rest_buf);
		result = malloc(1 * sizeof(char));
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	return (rest_buf);
}

static char	*get_line(char **rest_buf, char *read_buf, int fd)
{
	char	*line;
	int		bytes_read;
	int		line_end;

	if (**rest_buf)
	{
		*rest_buf = rest_to_read(*rest_buf, read_buf, &bytes_read);
        if (*rest_buf == NULL)
            return (NULL);
	}
	else
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read < 1)
			return (NULL);
	}
	line = NULL;
	while (bytes_read)
	{
		line_end = find_line_end(read_buf, bytes_read);
		line = append(line, read_buf, line_end + 1);
		if (read_buf[line_end] == '\n')
		{
            free(*rest_buf);
			*rest_buf = copy(read_buf, line_end + 1, bytes_read);
			if (*rest_buf == NULL)
			{
				free(line);
				return (NULL);
			}
			break;
		}
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rest_buf;
	char		*line;
    char	    *read_buf;

	if (rest_buf == NULL)
	{
		rest_buf = malloc(1 * sizeof(char));
		if (rest_buf == NULL)
			return (NULL);
		rest_buf[0] = '\0';
	}
    read_buf = malloc(BUFFER_SIZE * sizeof(char));
    if (read_buf == NULL)
    {
        free(rest_buf);
        rest_buf = NULL;
		return (NULL);
    }
	line = get_line(&rest_buf, read_buf, fd);
    free(read_buf);
	if (line == NULL)
    {
		free(rest_buf);
        rest_buf = NULL;
    }
	return (line);
}
