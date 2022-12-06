#include "main.h"

/*
 * execute_path - execute a program located at a specified path
 * @args: the arguments to pass to the program
 *
 * Returns 0 on success, -1 on error
 */
int execute_path(char *path, char **args)
{
    pid_t pid;
    int status;

    /* Create a child process to execute the command */
    pid = fork();
    if (pid == 0) {
        /* We are in the child process, so call execvp to execute the command at the given path */
        if (execvp(path, args) == -1) {
            perror("Error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        /* If fork() fails, print an error message and return -1 */
        perror("Error");
        return -1;
    } else {
        /* If we are in the parent process, wait for the child process to terminate */
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 0;
}