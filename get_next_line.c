/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 16:35:11 by aschenk           #+#    #+#             */
/*   Updated: 2014/12/31 16:13:52 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "includes/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>

size_t		find_next(char *str)
{
	size_t			i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0' && str[i] != EOF)
		i++;
	return (i);
}

int			ft_free(char **tmp3, char **buf, int ret)
{
	if (NULL != tmp3 && NULL != *tmp3)
	{
		free(*tmp3);
		*tmp3 = NULL;
	}
	if (NULL != buf && NULL != *buf)
	{
		free(*buf);
		*buf = NULL;
	}
	return (ret);
}

char		*buf_join(char **buf, char **tmp3)
{
	char			*tmp;

	if (*tmp3 != NULL)
	{
		tmp = *buf;
		*buf = ft_strjoin(*tmp3, *buf);
		free(tmp);
		free(*tmp3);
		*tmp3 = NULL;
	}
	return (*buf);
}

int			get_next_line(int const fd, char **line)
{
	ssize_t			size;
	size_t			i;
	char			*buf;
	char			*tmp;
	static char		*tmp3;

	if ((line == NULL || (*line = NULL)) ||
		!(buf = ft_memalloc(BUFF)))
		return (-1);
	while (fd >= 0 && line != NULL)
	{
		size = read(fd, buf, BUFF);
		buf_join(&buf, &tmp3);
		i = find_next(buf);
		tmp = (i && buf[0] != '\0') ? ft_strsub(buf, 0, i) : ft_strdup("");
		*line = buf_join(&tmp, line);
		if ((buf[i] == '\n' || (buf[i] == '\0' && buf[0] != 0 &&
			size <= 0)) && (tmp3 = ft_strdup(buf + i + 1)))
			return (ft_free(NULL, &buf, 1));
		if (buf[i] == EOF || (size == 0 && buf[0] == 0))
			return (ft_free(&tmp3, &buf, 0));
		buf = ft_memset(buf, '\0', ft_strlen(buf));
		ft_free(&tmp3, NULL, 0);
	}
	return (ft_free(NULL, &buf, -1));
}
