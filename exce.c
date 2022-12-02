#include "main.h"

int exec(char **args)
{
  pid_t pid;
  int status;
  
pid = fork();
if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (pid == 0)
	{
	for (status = 0; status < num_builtins(); status++)
    if (strcmp(args[0], builtin_str[status]) == 0) 
	{
      return (*je sais pas quoi mettre la[status])(args);
	}
	}
	else
	{
        wait(&status);
	}
	return (0);
}