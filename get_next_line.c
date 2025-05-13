#include "get_next_line.h"

char	*update_lineptr(char *lineptr)
{
	char	*res;

	if (!(ft_strchr(lineptr, '\n')))
		return (NULL);
	res = ft_strdup(ft_strchr(lineptr, '\n') + 1);
	if (!res)
	{
		free(lineptr);
		lineptr = NULL;
		return (NULL);
	}
	return (res);
}

char	*get_one_line(char *lineptr)
{
	char	*res;

	if (!ft_strchr(lineptr, '\n'))
		return (ft_strdup(lineptr));
	res = ft_strndup(lineptr, ft_strchr(lineptr, '\n') - lineptr + 1);
	if (!res)
	{
		free(lineptr);
		lineptr = NULL;
		return (NULL);
	}
	return (res);
}

char	*read_until_br(int fd, char *lineptr)
{
	char	*buf;
	int		rd;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(lineptr, '\n') && (rd = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd] = '\0';
		if (!(tmp = ft_strjoin(lineptr, buf)))
		{
			free(lineptr);
			free(buf);
			lineptr = NULL;
			return (NULL);
		}
		free(lineptr);
		lineptr = tmp;
	}
	free(buf);
	if (rd < 0)
		return (free(lineptr), lineptr = NULL, NULL);
	return (lineptr);
}

char	*get_next_line(int fd)
{
	static char *lineptr;
	char *res;
	char *tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr(lineptr, '\n'))
		lineptr = read_until_br(fd, lineptr);
	if (!lineptr || !*lineptr)
		return (free(lineptr), lineptr = NULL, NULL);
	if (!(res = get_one_line(lineptr)))
		return (free(lineptr), lineptr = NULL, NULL);
	if (!(tmp = update_lineptr(lineptr)))
		return (free(lineptr), lineptr = NULL, res);
	free(lineptr);
	lineptr = tmp;
	return (res);
}