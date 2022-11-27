/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:34:54 by zhizdahr          #+#    #+#             */
/*   Updated: 2021/12/10 15:34:55 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char	*s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void	*src, size_t	n)
{
	char		*d;
	const char	*s;

	d = (char *) dest;
	s = (const char *) src;
	if (d == 0 && s == 0)
		return (0);
	while (n)
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*m;
	int		s1_len;
	int		s2_len;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	m = (char *)malloc(sizeof(const char) * (s1_len + s2_len + 1));
	if (!m)
		return (0);
	ft_memcpy (m, s1, s1_len);
	ft_memcpy (&m[s1_len], s2, s2_len);
	m[s1_len + s2_len] = 0;
	free(s1);
	return (m);
}
