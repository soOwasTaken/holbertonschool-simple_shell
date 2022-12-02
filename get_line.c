#include "main.h"
char* read_line(void)
{
	size_t bufsize = 0;
    char *line = NULL;
	errno = 0;

if (getline(&line, &bufsize, stdin) == -1){
    if (feof(stdin)) {
        exit(EXIT_SUCCESS);
    } else  {
    perror("readline");
    exit(EXIT_FAILURE);
    }
}

  return line;
}