#include "main.h"
/**
 * cd - cd command of the shell
 * @args: name of the filename to be created.
 * Return: simple cd command (return 0);
 */
int cd(char **args)
{
	/* If no directory is specified, go to the user's home directory. */
	char *home_dir = getenv("HOME");

	if (home_dir == NULL)
	{
		perror("cd");
		return (0);
	}

	/* Use chdir to change the current working directory. */
	if (args[1] == NULL)
	{
		if (chdir(home_dir) != 0)
		{
			perror("cd");
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}

	return (0);
}
