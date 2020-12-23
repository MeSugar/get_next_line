/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:06:20 by gdelta            #+#    #+#             */
/*   Updated: 2020/12/24 01:35:22 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int next_line_exists(char **next_line, char **line)
{
    char *line_break;

	line_break = NULL;
	*line = ft_strdup(*next_line);
    if ((line_break = ft_strchr(*line, '\n')))
    {
        if (line_break++)
		{
            if (*line_break != '\n')
                --line_break;
            *line_break = '\0';
            ft_strcpy(*next_line, ++line_break);
        }
		return (1);
    }
    else
	{
		free(*next_line);
		*next_line = NULL;
		return (0);
	}
}

int get_next_line(int fd, char **line)
{
    char buf[BUFFER_SIZE + 1];
    int byte_reader;
    char *line_break;
    static char *next_line;
    char *tmp;

    if (fd < 1 || !line || BUFFER_SIZE < 1)
        return (-1);
    line_break = NULL;
    if (next_line)
        next_line_exists(&next_line, line);
    else
        *line = (char*)ft_calloc(1, 1);
    while(!next_line && !line_break && (byte_reader = read(fd, buf, BUFFER_SIZE)))
    {
        buf[byte_reader] = '\0';
        if((line_break = ft_strchr(buf, '\n')))
        {
            *line_break = '\0';
            next_line = ft_strdup(++line_break);
        }
        tmp = *line;
        *line = ft_strjoin(*line, buf);
        free(tmp);
    }
    if (byte_reader || ft_strlen(next_line) || ft_strlen(*line))
        return (1);
	return(0);
}

int main ()
{
    char *line;
    int fd;
    int a;

   fd = open("../text.txt", O_RDONLY);
    while ((a = get_next_line(fd, &line)))
    {
        //printf("%d\n\n", a);
		printf("%s\n", line);
		free(line);
    }
    free(line);
   	//sleep(100);
    return (0);
}
