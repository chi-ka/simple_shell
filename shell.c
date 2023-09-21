#include "main.h"

/**
 * main - Entry point for a simple shell.
 *
 * Return: Always 0.
 */
extern char **environ;

int main() 
{
	char *cmd = NULL;
	int is_all_spaces = 1, is_interactive = isatty(STDIN_FILENO);
	size_t i, cmd_size = 0;
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

		for (i = 0; i < strlen(cmd); i++)
		{
			if (cmd[i] != ' ') {
				is_all_spaces = 0;
				break;
			}
		}

		if (is_all_spaces)
		{
			continue;
		}

		if (strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			exit(0);
		}
		if (strcmp(cmd, "env") == 0)
		{
			char *env_var = *environ;

			while (env_var != NULL)
			{
				printf("%s\n", env_var);
				env_var = getenv(env_var);
			}
		}
		executeCommand(cmd);
	}
}
