#ifndef CUSTOM_SHELL_H
#define CUSTOM_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>

#define BUFFER_SIZE 1024
#define MAX_PATH_LENGTH 1024
#define MAX_BUFFER_SIZE 1024

/**
 * struct BufferInfo - Structure to hold buffer-related information.
 * @position: Current position in the buffer.
 * @bytesRead: Total bytes read into the buffer.
 * @buffer: The buffer to store data read from the input.
 */

struct BufferInfo
{
	int position;
	int bytesRead;
	char buffer[MAX_BUFFER_SIZE];
};

typedef struct BufferInfo BufferInfo;

char *check_and_refill_buffer(BufferInfo *info);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
unsigned int _strcspn(char *s, char *accept);
int _strlen(char *s);
int _pow(double a, double b);
int _atoi(char *s);
char *strtok_custom(char *str, const char *delimiters);
char **split_input(char *input, const char *delimiters);
void execute_command(char *command);
void print_env(char **env);
char *custom_getline(void);
void handle_exit(char *input, int *should_exit, int *exit_status);

#endif /* CUSTOM_SHELL_H */

