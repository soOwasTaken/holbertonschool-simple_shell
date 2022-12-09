#include "main.h"

/**
 * read_command - read and parse the command if
 * we are not in the interactive shell.
 * Return: void
 */
char **read_command(void)
{
	char delimiters[] = " \n\t\r";
	char *cmds = NULL;
	size_t cmds_len = 0;
	char *cmd = NULL, *context = NULL, **cmd_list = NULL, *cmds_copy = NULL;
	int num_cmds = 0;
	size_t i;

	if (getline(&cmds, &cmds_len, stdin) == -1)
	{
		fprintf(stderr, "Error: failed to read command from standard input\n");
		exit(1);
	}

	/* Remove the '\' character from the input string */
	for (i = 0; i < cmds_len; i++)
	{
		if (cmds[i] == '\\')
		{
			memmove(&cmds[i], &cmds[i + 1], cmds_len - i);
		}
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
		if (cmd_list == NULL)
			return (NULL);
		cmd_list[num_cmds] = cmd;
		num_cmds++;
		cmd = strtok_r(NULL, delimiters, &context);
	}
	free(cmds);
	return (cmd_list);
}

/**
 * execute - Executes a command given a list of arguments
 * @args: list of arguments to execute.
 * Return: void
 */
void execute(char **args)
{
	pid_t pid;
	int i;
	int ret;
	char *argument_list[2];

	for (i = 0; args[i] != NULL; i++)
	{
		pid = fork();
		if (pid == 0)
		{
			argument_list[0] = args[i];
			argument_list[1] = NULL;
			ret = execvp(args[i], argument_list);
			if (ret == -1)
			{
				perror("execvp");
				exit(0);
			}
		}
		else
		{
			waitpid(pid, NULL, 0);
		}
	}
}
/**
 * execute_command2 - Reads a command from standard input and run it.
 *
 * Return: void
 */
void execute_command2(void)
{
	char **args = read_command();

	execute(args);
	free(args);
	exit(0);
}
