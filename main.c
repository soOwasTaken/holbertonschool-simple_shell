#include "main.h"
/**
 * main - main entry
 * Return: return(0) when the shell is exited.
 */
int main(int argc, char *argv[])
{
	char *command = NULL;
	size_t size = 256;
	char **args = (char **)calloc(sizeof(char *), size);

	if (args == NULL)
	{
		fprintf(stderr, "Error: malloc() failed\n");
		exit(1);
	}
	args[0] = NULL;

	bool interactive = isatty(fileno(stdin));

	if (!interactive && argc > 1)
	{
		command = argv[1];
		for (int i = 2; i < argc; i++)
		{
			args[i-2] = argv[i];
		}
		args[argc-2] = NULL;

	execute_command(command, args);
	}
	else
	{
		while (true)
		{
			if (interactive)
			{
				printf("> ");
			}
			read_and_parse_command(&command, &args);
			if (command[0] == 0)
				continue;
			execute_command(command, args);
		free(command);
		}
	}

	return 0;
}
