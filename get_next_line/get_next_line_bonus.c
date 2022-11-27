/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:53:35 by zhizdahr          #+#    #+#             */
/*   Updated: 2021/12/10 17:47:35 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *str)
{
	char	*line;
	int		kol;

	kol = 1;
	line = (char *)malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (!ft_strchr(str, '\n') && kol > 0)
	{
		kol = read(fd, line, BUFFER_SIZE);
		if (kol == -1)
		{
			free(line);
			return (NULL);
		}
		line[kol] = '\0';
		str = ft_strjoin(str, line);
	}
	free(line);
	return (str);
}

char	*get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i] || !str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*save_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	line = (char *)malloc(ft_strlen(str) - i + 1);
	if (!line)
		return (0);
	j = 0;
	while (str[++i])
		line[j++] = str[i];
	line[j] = 0;
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str[900];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = read_line(fd, str[fd]);
	if (!str[fd])
		return (0);
	line = get_line(str[fd]);
	str[fd] = save_line(str[fd]);
	return (line);
}
