/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:44:01 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/01 18:48:49 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	isline(char *rem_text)
{
	int		i;

	i = 0;
	while (rem_text && rem_text[i])
	{
		if (rem_text[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*find_line(char *rem_text, int len)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		line[i] = rem_text[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}

int			get_next_line(int fd, char **line)
{
	static char	*rem_text[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	int			i;

	ret = BUFFER_SIZE;
	if (line == NULL || BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (-1);
	while ((i = isline(rem_text[fd])) == -1 && ret == BUFFER_SIZE)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		rem_text[fd] = ft_strjoin(rem_text[fd], buf);
	}
	if (i != -1 && (*line = find_line(rem_text[fd], i)) &&
	(rem_text[fd] = ft_substr(rem_text[fd], i + 1)))
		return (1);
	else
	{
		*line = rem_text[fd];
		rem_text[fd] = NULL;
		return (0);
	}
}
