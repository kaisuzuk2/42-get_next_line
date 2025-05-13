/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:53:02 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/05/13 20:04:25 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_lineptr(char *lineptr)
{
	char	*t;

	t = ft_strchr(lineptr, '\n');
	if (!t)
		return (NULL);
	return (ft_strdup(t + 1));
}

char	*get_oneline(char *lineptr)
{
	char	*t;

	t = ft_strchr(lineptr, '\n');
	if (!t)
		return (ft_strdup(lineptr));
	return (ft_strndup(lineptr, t - lineptr + 1));
}

char	*read_until_br(int fd, char *lineptr)
{
	char	*buf;
	int		read_len;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(lineptr, '\n'))
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len <= 0)
			break ;
		buf[read_len] = '\0';
		if (!(tmp = ft_strjoin(lineptr, buf)))
			break ;
		free(lineptr);
		lineptr = tmp;
	}
	free(buf);
	if (read_len == -1)
	{
		free(lineptr);
		lineptr = NULL;
	}
	return (lineptr);
}

char	*get_next_line(int fd)
{
	static char	*lineptr;
	char		*res;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr(lineptr, '\n') && !(lineptr = read_until_br(fd, lineptr)))
		return (NULL);
	if (*lineptr == '\0')
	{
		free(lineptr);
		lineptr = NULL;
		return (NULL);
	}
	res = get_oneline(lineptr);
	if (!(tmp = update_lineptr(lineptr)))
	{
		free(lineptr);
		lineptr = NULL;
		return (res);
	}
	free(lineptr);
	lineptr = tmp;
	return (res);
}
