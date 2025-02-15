#include "get_next_line.h"

int	find_new_line(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int		len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

static void	copy(char *dst, char *src, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

char	*ft_substr(char **s, int start, int len)
{
	char	*result;

	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
	{
		free(*s);
		*s = NULL;
		return (NULL);
	}
	copy(result, *s + start, len);
	result[len] = '\0';
	return (result);
}

void	append(char **line_buf, char *read_buf, int bytes_read)
{
	char	*temp;
	int		line_len;

	temp = *line_buf;
	line_len = ft_strlen(*line_buf);
	*line_buf = malloc((line_len + bytes_read + 1) * sizeof(char));
	if (*line_buf == NULL)
	{
		free(temp);
		return ;
	}
	(*line_buf)[line_len + bytes_read] = '\0';
	copy(*line_buf, temp, line_len);
	free(temp);
	copy(*line_buf + line_len, read_buf, bytes_read);
}
