#include "main.h"

/**
 * envCommand - Function to implement the 'env' built-in command.
 */
void envCommand(void)
{
	extern char **environ;
	char **env = environ;

	while (*env) {
		printf("%s\n", *env);
		env++;
	}
}
