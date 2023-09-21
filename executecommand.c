#include "main.h"

/**
 * executeCommand -function takes a command as input
 *
 * @cmd: The command to execute.
 */

void executeCommand(char *cmd)
{
	char *executable, *token, *argv[MAX_CMD_LEN];
	int status, argc = 0;
	pid_t pid;

	token = strtok(cmd, " ");
	while (token != NULL)
	{
		argv[argc++] = token;
		token = strtok(NULL, " ");
	}
	argv[argc] = NULL;
	executable = findExecutable(argv[0]);
	if (executable != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(executable, argv, NULL) == -1)
			{
				handleError(cmd);
				exit(1);
			}
		}
		else if (pid > 0)
		{
			if (waitpid(pid, &status, 0) == -1)
				handleError(cmd);
			else
				if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
					handleError(cmd);
		}
		else
		{
			handleError(cmd);
		}
		free(executable);
	}
	else
	{
		printf("Command not found: %s\n", argv[0]);
		handleError(cmd);
	}
}
