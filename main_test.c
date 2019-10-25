/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:43:24 by lnezonde          #+#    #+#             */
/*   Updated: 2019/10/22 15:17:05 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char *line;
	int fd;
	int res = 0;
	int i;

	line = NULL;
	fd = 0;
	i = 0;
	if ((fd = open("test.txt", O_RDONLY)) == -1)
		return (0);
	res = get_next_line(fd, &line);
	
	printf("%s (%d) \n", line, res);
	res = get_next_line(fd, &line);
	
	printf("%s (%d) \n", line, res);
	res = get_next_line(fd, &line);
	
	printf("%s (%d) \n", line, res);
	res = get_next_line(fd, &line);
	
	printf("%s (%d) \n", line, res);
	return (0);
}
