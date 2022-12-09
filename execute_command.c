#include "main.h"
/**
 * execute_command - create a new fille .
 * @command: command used
 * @args: args from getline
 * Return: return the attribued command from args.
 */
void execute_command(char *command, char **args)
{
	pid_t pid;
	int status = 1, i;
	bool command_found = false;

	if (command[0] == '/')
	{
		execute_path(command, args);
	}
	else
	{
		for (i = 0; commands[i].name != NULL; i++)
			if (strcmp(command, commands[i].name) == 0)
			{
				command_found = true;
				if (strcmp(command, "exit") == 0)
				{
					free(command);
					exit_shell(args);
				}
				pid = fork();
				if (pid < 0)
					fprintf(stderr, "Error: fork() failed\n");
				else if (pid == 0)
				{
					if (commands[i].func(args) == -1)
					{
						free(command);
						exit(0);
					}
				}
				else
					wait(&status);
			}
		if (!command_found)
		{
			fprintf(stderr, "Error: command not found\n");
			return;
		}
	}
}
