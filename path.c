#include "main.h"

/**
 * execute_path - execute a program located at a specified path
 * @command: path to execute
 * @args: the arguments to pass to the program
 *
 * Return: 0 on success, -1 on error
 */
int execute_path(char *command, char **args)
{
	pid_t pid;
	int status;

	/* Create a child process to execute the command */
	pid = fork();
	if (pid == 0)
	{
		if (execve(command, args, environ) == -1)
		{
			perror("Error");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* If fork() fails, print an error message and return -1 */
		perror("Error");
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

		/* Set status to 0 if the child process terminated normally */
		if (WIFEXITED(status))
		{
			status = 0;
		}
	}
	return (0);
}
