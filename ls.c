#include "main.h"
/* Function that executes the "ls" command */
int ls(char **args)
{
    // This line declares an array of strings called "argv" and initializes
    // it with the "/bin/ls" and "/usr/" strings
    char *argv[] = {"/bin/ls", "/usr/", NULL};

    // This if statement checks if the first two characters of the first
    // element in the "args" array are "ls". If they are, then it executes
    // the "/bin/ls" command with the "argv" array as its arguments.
    if (strncmp (args[0], "ls", 2) == 0)
        execve("/bin/ls", argv, NULL);

    // If the first two characters of the first element in the "args" array
    // are not "ls", then this else statement is executed, which prints an
    // error message to standard error and returns 1 to indicate failure.
    else {
        fprintf(stderr, "Error: invalid arguments for ls command\n");
        return 0;
    }

    // If the "ls" command is successfully executed, this line is reached,
    // which returns 0 to indicate success.
    return 0;
}