/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:44:01 by lnezonde          #+#    #+#             */
/*   Updated: 2019/10/22 13:17:30 by lnezonde         ###   ########.fr       */
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
	}
	return (-1);
}

static char	*find_line(char *rem_text, int len)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(sizeof(char) * len);
	while (i < len)
	{
		line[i] = rem_text[i];
		i++;
	}
	line[len] = '\0';
	rem_text += (len + 1);
	return (line);
}

int			get_next_line(int fd, char **line)
{
	static char	*rem_text = "";
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	int			i;

	if ((i = isline(rem_text)) != -1)
	{
		*line = find_line(rem_text, i);
		return (1);
	}
	while ((i = isline(rem_text)) != -1 && ret == BUFFER_SIZE)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		rem_text = ft_strjoin(rem_text, buf);
	}
	if (ret == BUFFER_SIZE)
		*line = find_line(rem_text, i);
	else if (ret < BUFFER_SIZE && ret >= 0)
	{
		*line = ft_strjoin(rem_text, buf);
		return (0);
	}
	else if (ret == -1)
			return (-1);
	printf("%s \n", *line);
	return (0);
}
