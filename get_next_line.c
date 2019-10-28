/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:44:01 by lnezonde          #+#    #+#             */
/*   Updated: 2019/10/28 14:19:10 by lnezonde         ###   ########.fr       */
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

static char	*find_line(char **rem_text, int len)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	tmp = *rem_text;
	line = malloc(sizeof(char) * len);
	while (i < len)
	{
		line[i] = tmp[i];
		i++;
	}
	line[len] = '\0';
	free(*rem_text);
	*rem_text = ft_strdup(tmp + len + 1);
	return (line);
}

int			get_next_line(int fd, char **line)
{
	static char	*rem_text = "";
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	int			i;

	ret = BUFFER_SIZE;
	while ((i = isline(rem_text)) == -1 && ret == BUFFER_SIZE)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		//if (ret != BUFFER_SIZE)
			//printf("b:%s\n", buf);
			//printf("r:%s\n", rem_text);
		rem_text = ft_strjoin(rem_text, buf);
		//printf("r2:%s\n", rem_text);

	}
	if (i != -1 && ret == BUFFER_SIZE)
	{
		*line = find_line(&rem_text, i);
		return (1);
	}
	if (ret < BUFFER_SIZE && ret >= 0)
	{
		*line = rem_text;
		return (0);
	}
	else if (ret == -1)
		return (-1);
	return (0);
}
