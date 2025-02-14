#include "get_next_line.h"

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

char	*copy(char *src, int start, int end)
{
	char	*result;
	int		i;

	result = malloc((end - start + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while ((i + start) < end)
	{
		result[i] = src[i + start];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	append(char **line, char *buf, int num_chars)
{
	char	*temp;
	int		i;
	int		line_len;

	temp = *line;
	line_len = ft_strlen(*line);
	*line = malloc((line_len + num_chars + 1) * sizeof(char));
	if (*line == NULL)
	{
		free(temp);
		return;
	}
	(*line)[line_len + num_chars] = '\0';
	i = 0;
	while (i < line_len)
	{
		(*line)[i] = temp[i];
		i++;
	}
    free(temp);
	i = 0;
	while (i < num_chars)
	{
		(*line)[line_len + i] = buf[i];
		i++;
	}
}

int	find_line_end(char *s, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (s[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (size - 1);
}
