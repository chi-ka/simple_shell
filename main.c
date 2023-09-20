#include <stdio.h>
#include "main.h"

/**
 * main - Entry point of the custom shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * @env: An array of strings containing the environment variables.
 *
 * Return: The exit status of the shell.
 */

int main(int argc, char **argv, char **env)
{
	int exit_status = 0;
	int should_exit = 0;

	(void)argc;
	(void)argv;

	while (!should_exit)
	{
		char *input_line = custom_getline();

		if (!input_line)
		{
			break;
		}
		input_line[_strcspn(input_line, "\n")] = '\0';

		if (_strlen(input_line) == 0)
		{
			continue;
		}
		else if (_strcmp(input_line, "env") == 0)
		{
			print_env(env);
		}
		else if (_strncmp(input_line, "exit", 4) == 0)
		{
			handle_exit(input_line, &should_exit, &exit_status);
		}
		else
		{
			char *token = strtok_custom(input_line, "|");

			{
				execute_command(token);
				token = strtok_custom(NULL, "|");
			}
		}
	}

	return (exit_status);
}
