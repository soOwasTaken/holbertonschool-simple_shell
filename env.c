#include "main.h"
/**
 * env - print the current environment variables
 * @args: command line arguments (not used)
 *
 * Return: always 0
 */
int env(char **args)
{
	char **envp;

	(void)args;
	for (envp = environ; *envp != NULL; envp++)
		printf("%s\n", *envp);
	return (0);
}
