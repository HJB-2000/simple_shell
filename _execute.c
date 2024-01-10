#include "shell.h"

/**
 * _execute - Executes a command with arguments
 * @command: An array of strings representing the command and its arguments
 * @argv: An array of strings representing the command-line arguments
 * @idx: The index of the command in the input sequence
 *
 * This function executes a command with arguments using fork and execve.
 * It returns the exit status of the command.
 *
 * Return: The exit status of the executed command
 */
int _execute(char **command, char **argv, int idx)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _getpath(command[0]);
	do {
		if (!full_cmd)
		{
			print_error(argv[0], command[0], idx);
			freearry(command);
			return (127);
		}
		break;
	} while (0);
	child = fork();
	while (1)
	{
		if (child == 0)
		{
			if (execve(full_cmd, command, environ) == -1)
			{
				free(full_cmd), full_cmd = NULL;
				freearry(command);
			}
		}
		else
		{
			waitpid(child, &status, 0);
			freearry(command);
			free(full_cmd), full_cmd = NULL;
		}
		break;
	}
	return (WEXITSTATUS(status));
}
