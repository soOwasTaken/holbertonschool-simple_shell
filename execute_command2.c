#include "main.h"

/**
 * execute_command - create a new file.
 * @command: command used
 * @args: args from getline
 * Return: return the attribued command from args.
 */
char **read_command(void)
{
	char delimiters[] = " \n\t\r";
	char *cmds = NULL;
	size_t cmds_len = 0;
	char *cmd = NULL, *context = NULL, **cmd_list = NULL, *cmds_copy = NULL;
	int num_cmds = 0;

	if (getline(&cmds, &cmds_len, stdin) == -1)
	{
		fprintf(stderr, "Error: failed to read command from standard input\n");
		exit(1);
	}
	cmds_copy = strdup(cmds);
	if (cmds_copy == NULL)
	{
		fprintf(stderr, "Error: failed to allocate memory\n");
		exit(1);
	}
	cmd = strtok_r(cmds_copy, delimiters, &context);
	while (cmd != NULL)
	{
		cmd_list = realloc(cmd_list, (num_cmds + 1) * sizeof(char *));
		cmd_list[num_cmds] = cmd;
		num_cmds++;
		cmd = strtok_r(NULL, delimiters, &context);
	}
	return (cmd_list);
}

/* Executes a command given a list of arguments*/
void execute(char **args)
{
	pid_t pid = fork();

	if (pid == 0)
		execvp(args[0], args);
	else
		waitpid(pid, NULL, 0);
}

/* Reads a command from standard input and executes it */
void execute_command2(void)
{
	char **args = read_command();

	execute(args);
}
