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

	bool interactive = isatty(fileno(stdin));

	if (!interactive && (argv || argc))
	{
		free(args);
		execute_command2();
		exit(0);
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

	return (0);
}
