#include "main.h"

int main()
{
    char *command = NULL; /* Command to be executed */
    size_t len = 0; /* Length of the command */
    size_t i = 0;
    pid_t pid;
    char *args[] = { NULL };
    int status = 1;
    bool command_found = false; /* Flag to indicate if the command was found in the list of built-in commands */

    /* Define a list of commands that can be executed */
    Command commands[] = {
        { "ls", ls },
        { "cd", cd },
        { "exit", exit_shell },
        { NULL, NULL }
    };

    /* Run the loop indefinitely */
    while (true) {
    /* Reset the len and i variables and the command_found flag before reading the next command */
    len = 0;
    i = 0;
    command_found = false;

    /* Display the prompt */
    printf("> ");

    /* Read the command from the user */
    if (getline(&command, &len, stdin) == -1) {
        /* If there is an error or end-of-file, exit the program */
        command[i] = 0;
        exit(0);
    }

    /* Remove the newline character at the end of the command */
    while (i < len && command[i] != '\n') {
        i++;
    }
    command[i] = 0;

    /* Set the first element of the args array to the name of the command entered by the user */
    args[0] = command;

    /* Check if the command is a path */
    if (command[0] == '/') {
        /* If the command is a path, call the execute_path function to execute it */
        if (execute_path(command, args) == -1) {
            continue;
        }
    } else {
        /* Iterate over the list of commands and execute the command if the name matches the command entered by the user */
        for (i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
            if (commands[i].name == NULL) {
                /* If the name field of the current command is NULL, we have reached the end of the array, so break out of the loop */
                break;
            }
            if (strcmp(command, commands[i].name) == 0) {
                /* Set the command_found flag to true */
                command_found = true;

                /* Check if the command is "exit" */
                if (strcmp(command, "exit") == 0) {
                    exit(0);
                }
                pid = fork();
                if (pid < 0) {
                    /* If fork() fails, print an error message and continue to the next iteration */
                    fprintf(stderr, "Error: fork() failed\n");
                } else if (pid == 0) {
                    /* If we are in the child process, execute the command using the function pointed to by the func field of the command structure */
                    if (commands[i].func(args) == -1) {
                        continue;
                    }
                } else {
                    /* If we are in the parent process, wait for the child process to terminate */
                    wait(&status);
                }
            }
        }

        /* If the command was not found in the list of built-in commands, print an error message */
        if (!command_found) {
            fprintf(stderr, "Error: command not found\n");
        }
    }
}

    free(command);
    return (0);
}