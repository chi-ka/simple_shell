#include <stdio.h>
#include "main.h"

/**
 * execute_command - Execute a single command.
 * @command: The command to execute.
 */
void execute_command(char *command)
{
	int status;
	pid_t child_pid;
	char *args[] = {NULL, NULL, NULL, NULL};

	args[0] = "/bin/sh";
	args[1] = "-c";
	args[2] = command;

	child_pid = fork();

	if (child_pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(args[0], args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
