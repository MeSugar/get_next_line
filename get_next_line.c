#include <fcntl.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"


int get_next_line(int fd, char **line)
{
    char buf[BUF_SIZE + 1];
    int byte_reader;
    char *line_break;
    static char *next_line;
    int stopper;
    char *tmp;

    stopper = 1;
    if (next_line)
    {
        *line = ft_strdup(next_line);
        if ((line_break = ft_strchr(*line, '\n')))
        {
            *line_break = '\0';
            next_line = ft_strdup(++line_break);
        } 
    }  
    else
        *line = (char*)ft_calloc(1, 1);
    while(stopper && (byte_reader = read(fd, buf, BUF_SIZE)))
    {
        buf[byte_reader] = '\0';
        if((line_break = ft_strchr(buf, '\n')))
        {
            *line_break = '\0';
            next_line = ft_strdup(++line_break);
            tmp = next_line;
            free(next_line);
            next_line = tmp;
            stopper--;
        }
        *line = ft_strjoin(*line, buf);
    }
    if(next_line)
        return (1);     
    return(0);
}

int main()
{
    int fd;
    char *line;

    if((fd = open("text.txt", O_RDONLY)) == -1)
    {
        printf("error");
        return(0);
    }
    get_next_line(fd, &line);
    printf("%s\n\n", line);

    get_next_line(fd, &line);
    printf("%s\n\n", line);

    get_next_line(fd, &line);
    printf("%s\n\n", line);
    return (0);
}

