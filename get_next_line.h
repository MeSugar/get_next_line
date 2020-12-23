/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:13:34 by gdelta            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/12/21 23:53:34 by gdelta           ###   ########.fr       */
=======
/*   Updated: 2020/12/22 21:30:01 by student          ###   ########.fr       */
>>>>>>> 2e9cdcb82c91c7c8b28edd27e1382ade5f8ee8f8
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUF_SIZE
<<<<<<< HEAD
# define BUF_SIZE 10000
=======
# define BUF_SIZE 5
>>>>>>> 2e9cdcb82c91c7c8b28edd27e1382ade5f8ee8f8
#endif
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);

#endif
