#include "main.h"

/**
 * executeCommand - Execute a given command.
 * @cmd: The command to execute.
 * @commandStatus: Pointer to an integer.
 */

void executeCommand(char *cmd, int *commandStatus)
{
	char *executable, *argv[MAX_CMD_LEN];
	int argc;
	pid_t pid, status;

	if (parseCommand(cmd, argv, &argc) <= 0)
	{
		*commandStatus = 1;
		return;
	}
	executable = findExecutable(argv[0]);
	if (executable == NULL)
	{
		printf("Command not found: %s\n", argv[0]);
		handleError(cmd);
		*commandStatus = 1;
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		handleError(cmd);
		free(executable);
		*commandStatus = 1;
		return;
	}
	if (pid == 0)
	{
		if (execve(executable, argv, NULL) == -1)
			handleError(cmd);
		exit(1); }
	else
	{
		if (waitpid(pid, &status, 0) == -1)
			handleError(cmd);
		else
			if (WIFEXITED(status))
				*commandStatus = WEXITSTATUS(status);
		if (*commandStatus != 0)
			handleError(cmd);
		free(executable); }
}
