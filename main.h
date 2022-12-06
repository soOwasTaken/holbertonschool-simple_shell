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
#include <readline/readline.h>

/* Define a structure for a command */
typedef struct Command {
    char *name;
    int (*func)(char **);
} Command;

int exit_shell(char **args);
int ls(char **args);
int cd(char **args);
int shell_path(char **path);
int execute_path(char *path, char *args[]);
int launchshell();
int execute_path(char *command, char **args);
void read_and_parse_command(char **command, char ***args);
void execute_command(char *command, char **args);

#endif