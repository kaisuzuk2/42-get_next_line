/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:18:33 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/05/13 21:54:50 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*res;
	char	*p;

	len = 0;
	while (s[len])
		len++;
	if (n < len)
		len = n;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	p = res;
	while (*s && len--)
		*p++ = *s++;
	*p = '\0';
	return (res);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*res;
	char	*p;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len])
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	p = res;
	while (*s)
		*p++ = *s++;
	*p = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*p;
	char const *tmp;
	int len;

	len = 0;
	if (!s1)
		s1 = "\0";
	tmp = s1;
	while (*tmp++)
		len++;
	tmp = s2;
	while (*tmp++)
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	p = res;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = '\0';
	return (res);
}
