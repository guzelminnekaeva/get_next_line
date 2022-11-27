/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:35:00 by zhizdahr          #+#    #+#             */
/*   Updated: 2021/12/10 15:35:01 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*ft_strchr(char	*s, int c);
size_t	ft_strlen(char *s);
void	*ft_memcpy(void *dest, const void	*src, size_t	n);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
#endif