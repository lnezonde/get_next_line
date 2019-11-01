/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:43:24 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/01 16:51:49 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h> // a retirer
# include <sys/types.h> // a retirer
# include <sys/stat.h> // a retirer
# include <fcntl.h> // a retirer

int	main(int ac, char **av)
{
	char *line;
	int fd;
	int fd2;
	int res = 1;
	int res2 = 1;
	int i;
	ac = 1;

	line = NULL;
	fd = 0;
	i = 0;
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	while (res == 1 || res2 == 1)
	{
		res = get_next_line(fd, &line);
		(res == 1) ? printf("+%s (%d) \n", line, res) : 0;
		line ? free(line) : 0;
		res2 = get_next_line(fd2, &line);
		(res2 == 1) ? printf("-%s (%d) \n", line, res2) : 0;
		(line) ? free(line) : 0;
	}
	return (0);
}
