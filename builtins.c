#include "shell.h"
/**
 * shell_exit - Exits the shell with a specified status
 * @cmd: The array of strings representing the command and its arguments
 * @argv: The array of strings representing the command-line arguments
 * @status: A pointer to the shell status
 * @idx: The index of the command in the input sequence
 *
 * This function handles the 'exit' built-in command, allowing the user
 * to exit the shell with an optional status. If the status is not a valid
 * number, an error message is displayed.
 */
void shell_exit(char **cmd, char **argv, int *status, int idx)
{
	int v = (*status);
	char *i, message[] = ": exit: Illegal number: ";

	if (cmd[1])
	{
		if (num_checker(cmd[1]))
		{
			v = _atoi(cmd[1]);
		}
		else
		{
			i = _itoa(idx);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, i, _strlen(i));
			write(STDERR_FILENO, message, _strlen(message));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(i), i = NULL;
			freearry(cmd);
			(*status) = 2;
			return;
		}

	}
	freearry(cmd);
	exit(v);
}

