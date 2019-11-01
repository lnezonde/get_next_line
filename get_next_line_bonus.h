/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:35:22 by lnezonde          #+#    #+#             */
/*   Updated: 2019/11/01 16:08:05 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int	ft_strlen(const	char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dst, const void *src, int n);
char	*ft_substr(char *s, unsigned int start);
char	*ft_strdup(char *s1);
int		get_next_line(int fd, char **line);
#endif
