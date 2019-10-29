/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <lnezonde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:34:29 by lnezonde          #+#    #+#             */
/*   Updated: 2019/10/29 22:53:34 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const	char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s_new;
	int		len_tt;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	len_tt = ft_strlen(s1) + ft_strlen(s2);
	if (!(s_new = malloc(sizeof(char) * (len_tt + 1))))
		return (NULL);
	while (s1[i2])
		s_new[i++] = s1[i2++];
	i2 = 0;
	while (s2[i2])
		s_new[i++] = s2[i2++];
	if (*s1)
		free (s1);
	s1 = NULL;
	s_new[i] = '\0';
	return (s_new);
}

char	*ft_substr(char *s, unsigned int start)
{
	char	*s_new;
	int len;
	int	i;

	i = 0;
	len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (!(s_new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len-- && s[start])
		s_new[i++] = s[start++];
	s_new[i] = '\0';
	if (*s)
		free (s);
	s = NULL;
	return (s_new);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	if (!(copy = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	if (*src)
		free(src);
	copy[i] = '\0';
	return (copy);
}
