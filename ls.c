#include "main.h"
/**
 * ls - create a new fille .
 * @args: here there is no args needed yet
 * Return: return(0);
 */
int ls(char **args)
{
	char *argv[] = {"/bin/ls", "/usr/", NULL};

	if (strncmp(args[0], "ls", 2) == 0)
		execve("/bin/ls", argv, NULL);
	else
	{
		fprintf(stderr, "Error: invalid arguments for ls command\n");
		return (0);
	}
	return (0);
}
