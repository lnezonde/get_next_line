/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:44:01 by lnezonde          #+#    #+#             */
/*   Updated: 2019/10/21 19:00:32 by lnezonde         ###   ########.fr       */
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
			return (1);
	}
	return (0);
}

static char	*make_line(char *rem_text, int i)
{
	int j;
	int i2;
	char *tmp;

	j = i;
	i2 = 0;
	if(!(tmp = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i2 < i)
	{
		tmp[i2] = rem_text[i2];
		i2++;
	}
	rem_text += (i + 1);
	return (tmp);
}

int			get_next_line(int fd, char **line)
{
	static char	*rem_text = "";
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	int			i;

	if (isline(rem_text))
	{
		*line = make_line(rem_text, i);
		return (1);
	}
	while (1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if ((i = find_line(rem_text, buf)) != -1 && ret == BUFFER_SIZE)
		{
			*line = make_line(rem_text, i);
			return (1);
		}
		else if (ret < BUFFER_SIZE && ret >= 0)
		{
			*line = make_line(rem_text, ft_strlen(rem_text) + 1);
			return (0);
		}
		else if (ret == -1)
			return (-1);
	}
	return (0);
}
