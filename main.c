#include "main.h"
/**
 * main - main entry
 * Return: return(0) when the shell is exited.
 */
int main(void)
{
	char *command = NULL;
	char **args = (char **)malloc(sizeof(char *));

	if (args == NULL)
	{
		fprintf(stderr, "Error: malloc() failed\n");
		exit(1);
	}
	args[0] = NULL;

	while (true)
	{
		read_and_parse_command(&command, &args);
		if (command[0] == 0)
			continue;
		execute_command(command, args);
	}

	free(command);
	free(args);
	return (0);
}
