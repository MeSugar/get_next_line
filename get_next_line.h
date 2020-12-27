/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:44:05 by gdelta            #+#    #+#             */
/*   Updated: 2020/12/27 20:45:59 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
int		get_next_line(int fd, char **line);

#endif
