#include "main.h"
/**
 * read_and_parse_command - fonction to read and parse command aka getline
 * @command: command used
 * @args: args in the getlines
 * Return: lenght of what will be printed
 *
 */
void read_and_parse_command(char **command, char ***args)
{
	size_t len = 0;

	if (getline(command, &len, stdin) == -1)
	{
		free(*command);
		exit_shell(*args);
	}
	if (strcmp(*command, "exit") == 0)
	{
		free(command);
		return;
	}
	if (**command == '\n' || **command == EOF)
	{
		free(command);
		return;
	}

	(*command)[strcspn(*command, "\n")] = 0;
	(*args)[0] = *command;
}
