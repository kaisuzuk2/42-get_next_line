#include "get_next_line.h"

int	read_until_br(int fd, char **lineptr)
{
	int		read_len;
	char	*buf;
	char	*joined;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	read_len = read(fd, buf, BUFFER_SIZE);
	if (read_len <= 0)
	{
		free(buf);
		return (-1);
	}
	buf[read_len] = '\0';
	joined = ft_strjoin(*lineptr, buf);
	free(buf);
	free(*lineptr);
	*lineptr = joined;
	return (1);
}

char	*get_next_line(int fd)
{
	static char *lineptr;
	char *t;
	size_t len;
	char *res;
	char *tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((t = ft_strchr(lineptr, '\n')) == NULL)
	{
		if (read_until_br(fd, &lineptr) == -1)
			break ;
	}
	if (t)
	{
		len = t - lineptr + 1;
		res = ft_strndup(lineptr, len);
		tmp = ft_strdup(t + 1);
		free(lineptr);
		lineptr = tmp;
		return (res);
	}
	if (lineptr && *lineptr)
	{
		res = lineptr;
		lineptr = NULL;
		return (res);
	}
	free(lineptr);
	lineptr = NULL;
	return (NULL);
}