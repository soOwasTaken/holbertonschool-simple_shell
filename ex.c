#include "main.h"
/**
 * exit_shell - create a new fille .
 * @args: here there is no args needed.
 * Return: return(0);
 */
int exit_shell(char **args)
{
		free(args);
		exit(0);
}
