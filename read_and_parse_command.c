#include "main.h"
void read_and_parse_command(char **command, char ***args) {
    size_t len = 0;

    printf("> ");

    if (getline(command, &len, stdin) == -1) {
        (*command)[0] = 0;
        exit(0);
    }

    if (**command == '\n') {
        return;
    }

    (*command)[strcspn(*command, "\n")] = 0;
    (*args)[0] = *command;
}