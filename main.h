#ifndef main_h
#define main_h
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* Define a structure for a command */
typedef struct {
    char *name; /* Name of the command */
    int (*func)(char **); /* Function pointer to the function that executes the command */
} Command;
int exit_shell(char **args);
int ls(char **args);
int cd(char **args);
int shell_path(char **path);
int execute_path(char *path, char *args[]);
int launchshell();

#endif