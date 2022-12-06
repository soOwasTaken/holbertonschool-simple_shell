#include "main.h"
/* Function that executes the "ls" command */
int ls(char **args)
{
    char *argv[] = {"/bin/ls", "/usr/", NULL};

    if (strncmp (args[0], "ls", 2) == 0)
        execve("/bin/ls", argv, NULL);
    else {
        fprintf(stderr, "Error: invalid arguments for ls command\n");
        return 0;
    }
    return 0;
}