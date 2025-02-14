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

char	*append(char *line, char *buf, int num_chars)
{
	char	*result;
	int		i;
	int		line_len;

	line_len = ft_strlen(line);
	result = malloc((line_len + num_chars + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[line_len + num_chars] = '\0';
	i = 0;
	while (i < line_len)
	{
		result[i] = line[i];
		i++;
	}
    free(line);
	i = 0;
	while (i < num_chars)
	{
		result[line_len + i] = buf[i];
		i++;
	}
	return (result);
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
