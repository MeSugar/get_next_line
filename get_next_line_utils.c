/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:14:02 by gdelta            #+#    #+#             */
/*   Updated: 2020/12/22 21:17:22 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	if (!s)
		return (0);
	len = 0;
	if (!s)
	    return (len);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	if (!(s3 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

void	*ft_calloc(size_t count, size_t size)
{
	void *i;

	i = malloc(count * size);
	if (i == 0)
		return (0);
	ft_memset(i, 0, count * size);
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;

	str = (unsigned char*)b;
	while (len)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char*)&s[i]);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	if (!(s2 = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (0);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t j;

	if (!dst || !src)
		return (0);
	j = 0;
	while (src[j])
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
