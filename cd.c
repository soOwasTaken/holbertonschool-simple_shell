#include "main.h"
/**
 * cd - cd command of the shell
 * @args: name of the filename to be created.
 * Return: simple cd command (return 0);
 */
int cd(char **args)
{
	execute(args);
	return (0);
}
