#include "main.h"

char **split_line(char *line)
{
	int bufsize = 32,position = 0;
	char s[2] = " -";
	char **args = malloc(bufsize * sizeof(char*));
	char *arg;
	arg = strtok(line,s);
	while (arg != NULL)
	{
		args[position] = arg;
			position++;

		if (position >= bufsize)
		{
			bufsize += bufsize;
			args = realloc(args, bufsize * sizeof(char*));
			if (!args)
			{
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		arg = strtok(NULL, s);
	}
	args[position] = NULL;
	return(args);
}