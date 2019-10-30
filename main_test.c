/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:43:24 by lnezonde          #+#    #+#             */
/*   Updated: 2019/10/30 17:08:08 by lnezonde         ###   ########.fr       */
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
	if ((fd = open("/Users/lnezonde/Desktop/get_next_line/42TESTERS-GNL/files/41_char", O_RDONLY)) == -1)
		return (0);
	while ((res = get_next_line(fd, &line)) == 1)
	{
		printf("%s (%d) \n", line, res);
		free(line);
		line = NULL;
	}
	printf("%s (%d) \n", line, res);
	free(line);
	line = NULL;
	return (0);
}
