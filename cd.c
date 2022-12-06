#include "main.h"
/* Function that executes the "cd" command */
int cd(char **args) {
    if (args[1] == NULL)
    {
        // If no directory is specified, go to the user's home directory.
        char *home_dir = getenv("HOME");
        if (home_dir == NULL)
        {
            perror("cd");
            return 0;
        }

        // Use execvp to execute the "cd" command with the specified directory.
        char *cmd = "cd";
        char *argv[] = {cmd, home_dir, NULL};
        execvp(cmd, argv);
    }
    else
    {
        // Use execvp to execute the "cd" command with the specified directory.
        char *cmd = "cd";
        char *argv[] = {cmd, args[1], NULL};
        execvp(cmd, argv);
    }

    return 0;
}