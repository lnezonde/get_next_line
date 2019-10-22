/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:35:22 by lnezonde          #+#    #+#             */
/*   Updated: 2019/10/22 14:50:32 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> // a retirer
# include <sys/types.h> // a retirer
# include <sys/stat.h> // a retirer
# include <fcntl.h> // a retirer
# define BUFFER_SIZE 4
size_t	ft_strlen(const	char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
int		get_next_line(int fd, char **line);




#endif
