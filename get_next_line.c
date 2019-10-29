/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:44:01 by lnezonde          #+#    #+#             */
/*   Updated: 2019/10/29 23:00:37 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	isline(char *rem_text)
{
	int		i;

	i = 0;
	while (rem_text[i])
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
	static char	*rem_text = "";
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			ret;
	int			i;

	ret = BUFFER_SIZE;
	if (line == NULL || BUFFER_SIZE == 0)
		return (-1);
	while ((i = isline(rem_text)) == -1 && ret == BUFFER_SIZE)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		tmp = ft_strdup(rem_text);
		rem_text = ft_strjoin(tmp, buf);
	}
	if (i != -1)
	{
		*line = find_line(rem_text, i);
		tmp = ft_strdup(rem_text);
		rem_text = ft_substr(tmp, i + 1);
		return (1);
	}
	if (ret < BUFFER_SIZE && ret >= 0)
	{
		*line = rem_text;
		rem_text = "";
		return (0);
	}
	else if (ret == -1)
		return (-1);
	return (0);
}
