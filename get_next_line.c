/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:12:50 by gdelta            #+#    #+#             */
/*   Updated: 2020/12/21 01:00:33 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int next_line_exists(char **next_line, char **line)
{
    char *line_break;
    char *tmp;

	line_break = 0;
	*line = ft_strdup(*next_line);
    if ((line_break = ft_strchr(*line, '\n')))
    {
        *line_break = '\0';
		ft_strcpy(*next_line, ++line_break);
        return (1);    
    }
    else
	{
		while (*next_line)
			*next_line++ = "\0";
		return (0);
	}
}

int get_next_line(int fd, char **line)
{
    char buf[BUF_SIZE + 1];
    int byte_reader;
    char *line_break;
    static char *next_line;
    char *tmp;

    if (fd < 1 || !line || BUF_SIZE <= 0)
        return (-1);
    line_break = 0;
    if (next_line)
        next_line_exists(&next_line, line);
    else
        *line = (char*)calloc(1, 1);
    while(!line_break && (byte_reader = read(fd, buf, BUF_SIZE)))
    {
        buf[byte_reader] = '\0';
        if((line_break = ft_strchr(buf, '\n')))
        {
            *line_break = '\0';
            next_line = ft_strdup(++line_break);
			tmp = next_line;
			free(tmp);
        }
        tmp = *line;
        *line = ft_strjoin(*line, buf);
        free(tmp);
    }
    if(byte_reader || ft_strlen(next_line) || ft_strlen(*line))
        return (1);
	return(0);
}

int main ()
{
    char *line;
    int fd;
    int a;

    fd = open("text.txt", O_RDONLY);
    while((a = get_next_line(fd, &line)))
	{
        printf("return:%d\n", a);
        printf("string:%s\n\n", line);
		free(line);
	}
    printf("return:%d\n", a);
	free(line);
	//leep(100);
    return(0);
}
