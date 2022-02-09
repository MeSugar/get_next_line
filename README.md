## About
The function can be used in a loop and gives a way to read content line by line from a given file descriptor until the end of the file.

Prototype:
```C
char *get_next_line(int fd);
```

Returning values

-1 if an error occurred, 0 if there is nothing to read in the file, 1 if the line was successfully read

## Usage
Include header file to your programm and compile it whith .c files needed by GNL.
```C
#include "get_next_line.h"
```
