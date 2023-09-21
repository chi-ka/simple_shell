#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#define MAX_CMD_LEN 128

void executeCommand(char *cmd);
void handleError(char *cmd);

int main() 
{
	char *cmd = NULL;
	int is_interactive = isatty(STDIN_FILENO);
	size_t cmd_size = 0;
	ssize_t getline_result;

	while (1)
	{
		if (is_interactive)
		{
			write(STDOUT_FILENO, ":) ", 3);
		}

		getline_result = getline(&cmd, &cmd_size, stdin);

		if (getline_result == -1)
		{
			if (is_interactive) 
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			free(cmd);
			exit(0);
		}

		cmd[getline_result - 1] = '\0';

		executeCommand(cmd);
	}
}

void executeCommand(char *cmd)
{
	char *token = strtok(cmd, " ");
	char *argv[MAX_CMD_LEN];
	int argc = 0;
	pid_t pid;
	int status;

	while (token != NULL)
	{
		argv[argc++] = token;
		token = strtok(NULL, " ");
	}

	argv[argc] = NULL;

	if (access(argv[0], X_OK) == 0)
	{
		if ((pid = fork()) == 0)
		{
			if (execve(argv[0], argv, NULL) == -1) 
			{
				handleError(cmd);
				exit(1);
			}
		}
		else if (pid > 0)
		{
			if (waitpid(pid, &status, 0) == -1) 
			{
				handleError(cmd);
			}
			else
			{
				if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
				{
					handleError(cmd);
				}
			}
		}
		else
		{
			handleError(cmd);
		}
	}
	else if (access(argv[0], F_OK) == -1)
	{
		char *path_copy, *path, *token;

		path = getenv("PATH");
		if (path == NULL)
		{
			perror("Failed to get PATH environment variable");
			exit(EXIT_FAILURE);
		}

		path_copy = strdup(path); 
		token = strtok(path_copy, ":");
		while (token != NULL)
		{
			char executable[MAX_CMD_LEN];
			snprintf(executable, sizeof(executable), "%s/%s", token, argv[0]);
			if (access(executable, X_OK) == 0)
			{
				if ((pid = fork()) == 0)
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
					{
						handleError(cmd);
					}
					else
					{
						if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
						{
							handleError(cmd);
						}
					}
				}
				else
				{
					handleError(cmd);
				}
				free(path_copy);
				return;
			}
			token = strtok(NULL, ":");
		}

		free(path_copy);
		printf("Command not found: %s\n", argv[0]);
	}
	else
	{
		handleError(cmd);
	}
}

void handleError(char *cmd)
{
	char error_msg[128];
	strcpy(error_msg, cmd);
	strcat(error_msg, ": ");
	strcat(error_msg, strerror(errno));
	strcat(error_msg, "\n");
	write(STDERR_FILENO, error_msg, strlen(error_msg));
}

