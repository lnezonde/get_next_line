/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:34:29 by lnezonde          #+#    #+#             */
/*   Updated: 2019/10/16 18:18:04 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const	char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_new;
	int		len_tt;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (NULL);
	len_tt = ft_strlen(s1) + ft_strlen(s2);
	if (!(s_new = malloc(sizeof(char) * (len_tt + 1))))
		return (NULL);
	while (s1[i2])
		s_new[i++] = s1[i2++];
	i2 = 0;
	while (s2[i2])
		s_new[i++] = s2[i2++];
	s_new[i] = '\0';
	return (s_new);
}
