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
#endif