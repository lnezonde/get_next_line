/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:43:24 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/01 16:11:49 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	char *line;
	int fd;
	int res = 1;
	int i;
	ac = 1;

	line = NULL;
	fd = 0;
	i = 0;
	fd = open(av[1], O_RDONLY);
	while (res == 1)
	{
		res = get_next_line(fd, &line);
		printf("%s (%d) \n", line, res);
		free(line);
		line = NULL;
	}
	close(fd);
	fd = open(av[2], O_RDONLY);
	while (res == 1)
	{
		res = get_next_line(fd, &line);
		printf("%s (%d) \n", line, res);
		free(line);
		line = NULL;
	}
	return (0);
}
