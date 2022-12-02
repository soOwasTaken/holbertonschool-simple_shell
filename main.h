#ifndef main_h
#define main_h
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
char* read_line();
char** split_line(char *line);
int exec(char **args);
int _exit(char **args);
char *builtin_str[];
int _help(char **args);
int _cd(char **args);
int num_builtins();
int _putchar(char c);

#endif
