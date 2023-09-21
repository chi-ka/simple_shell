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

/**
 * main - Entry point for a simple shell.
 *
 * Return: Always 0.
 */

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
            write(STDOUT_FILENO, "#cisfun$ ", 9);
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

/**
 * executeCommand - Execute a command specified by 'cmd'.
 * @cmd: The command to execute.
 *
 */

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
    }
    else
    {
        handleError(cmd);
    }
}

/**
 * handleError - Handle errors by printing an error message to STDERR.
 * @cmd: The command associated with the error.
 *
 */

void handleError(char *cmd)
{
    char error_msg[128];
    strcpy(error_msg, cmd);
    strcat(error_msg, ": ");
    strcat(error_msg, strerror(errno));
    strcat(error_msg, "\n");
    write(STDERR_FILENO, error_msg, strlen(error_msg));
}

