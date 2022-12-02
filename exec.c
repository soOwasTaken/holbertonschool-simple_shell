#include "main.h"
int exec(char **args)
{
  pid_t pid;
  int status;
  char *argv[] = {"/bin/ls", "/usr/", NULL};
  char *argv2[] = {"/bin/ls", "-la", "/usr/", NULL};

pid = fork();
if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (pid == 0)
	{
		if ((strncmp (args[0], "ls", 2) == 0) && (args[1] == NULL))
			execve("/bin/ls", argv, NULL);
		if ((strncmp (args[0], "ls", 2)) == 0 && ((strncmp(args[1], "la", 2)) == 0))
			execve("/bin/ls", argv2, NULL);
	}
	else
	{
		wait(&status);
	}
	return (0);
}