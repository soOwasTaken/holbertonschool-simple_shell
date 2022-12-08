#include "main.h"
/**
 * main - main entry
 * Return: return(0) when the shell is exited.
 */
int main(void)
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

	while (true)
	{
		if (isatty(fileno(stdin)))
		{
			printf("> ");
		}
		read_and_parse_command(&command, &args);
		if (command[0] == 0)
			continue;
		execute_command(command, args);
		free(command);
	}
	return (0);
}
