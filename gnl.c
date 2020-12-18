#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


int get_next_line(int fd, char **line)
{
    char buf[BUF_SIZE + 1];
    int byte_reader;
    char *end_of_line;
    static char *begin_of_line;
    int stopper;

    stopper = 1;
    if (begin_of_line)
        *line = ft_strdup(begin_of_line);
    else
        *line = (char*)ft_calloc(1, 1);
    while(stopper && (byte_reader = read(fd, buf, BUF_SIZE)))
    {
        buf[byte_reader] = '\0';
        if(end_of_line = ft_strchr(buf, '\n'))
        {
            *end_of_line = '\0';
            begin_of_line = ft_strdup(++end_of_line);
            stopper--;
        }
        *line = ft_strjoin(*line, buf);
    }
    
    
    return(0);
}

int main()
{
    int fd;
    char *line;

    fd = open("text.txt", O_RDONLY);
    get_next_line(fd, &line);
    printf("%s\n\n", line);

    get_next_line(fd, &line);
    printf("%s\n\n", line);

    return (0);
}

