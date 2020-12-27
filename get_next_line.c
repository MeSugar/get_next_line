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
    if ((line_break = ft_strchr(*next_line, '\n')))
    {
        //if (line_break + 1)
		//{
            *line_break = '\0';
            *line = ft_strdup(*next_line);
            if (*(line_break + 1))
                ft_strcpy(*next_line, ++line_break);
            else
            {
                free(*next_line);
		        *next_line = NULL;
                return (0);
            }
		return (1);
    }
    else
	{
        *line = ft_strdup(*next_line);
		free(*next_line);
		*next_line = NULL;
		return (1);
	}
}

int get_next_line(int fd, char **line)
{
    char buf[BUFFER_SIZE + 1];
    int byte_reader;
    char *line_break;
    static char *next_line;
    char *tmp;

    if (fd < 0 || !line || BUFFER_SIZE < 1)
        return (-1);
    line_break = NULL;
    byte_reader = 1;
    if (next_line)
    {
        if (!(next_line_exists(&next_line, line)))
            return (1);
    }
    else
        *line = (char*)ft_calloc(1, 1);
    while(!next_line && !line_break && byte_reader)
    {
        if ((byte_reader = read(fd, buf, BUFFER_SIZE)) < 0)
            return (-1);
        buf[byte_reader] = '\0';
        if((line_break = ft_strchr(buf, '\n')))
        {
            *line_break = '\0';
            if (*(line_break + 1))
                next_line = ft_strdup(++line_break);
            else
            {
                free(next_line);
		        next_line = NULL;
	        }
        }
        tmp = *line;
        *line = ft_strjoin(*line, buf);
        free(tmp);
    }
    if (byte_reader || ft_strlen(next_line))
       return (1);
	//return ((byte_reader == 0) ? 0 : 1);
    return (0);
}

// int main ()
// {
//     char *line;
//     int fd;
//     int a;

//     a = 1;
//    fd = open("text.txt", O_RDONLY);
//     while (a)
//     {
//         (a = get_next_line(fd, &line));
//         //printf("%d\n\n", a);
// 		printf("%s\n", line);
// 		free(line);
//     }
//      //free(line);
//    	// sleep(100);
//     return (0);
//
