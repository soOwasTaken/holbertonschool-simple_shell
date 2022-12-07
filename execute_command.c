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
	int status = 1;
	int i;
	bool command_found = false;

	if (command[0] == '/')
	{
		if (execute_path(command, args) == -1)
			return;
	}
	else
	{
		for (i = 0; commands[i].name != NULL; i++)
		{
			if (strcmp(command, commands[i].name) == 0)
			{
				command_found = true;
				if (strcmp(command, "exit") == 0)
					exit(0);
				pid = fork();
				if (pid < 0)
					fprintf(stderr, "Error: fork() failed\n");
				else if (pid == 0)
				{
					if (commands[i].func(args) == -1)
						return;
				}
				else
					wait(&status);
				}
		}
		if (!command_found)
			fprintf(stderr, "Error: command not found\n");
	}
}
