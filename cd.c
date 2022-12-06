#include "main.h"
/* Function that executes the "cd" command */
int cd(char **args) {
    if (args[1] == NULL)
    {
        // If no directory is specified, go to the user's home directory.
        if (chdir(getenv("HOME")) != 0)
        {
            perror("cd");
            return 0;
        }
    }
    else
    {
        // Change to the specified directory.
        if (chdir(args[1]) != 0)
        {
            perror("cd");
            return 0;
        }
    }
    return 0;
}