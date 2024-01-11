#include "shell.h"
/**
 * cmd_checker - Checks if a command is a built-in command
 * @cmd: The command to check
 *
 * This function checks if the given command is a built-in command
 * by comparing it with a list of known built-in commands.
 *
 * Return: 1 if the command is a built-in, 0 otherwise
 */
int cmd_checker(char *cmd)
{
	char *other_cmd[] = {"cd", "setenv", "env", "exit", "exit()", NULL};
	int i = 0;

	while (other_cmd[i])
	{
		if (_strcmp(cmd, other_cmd[i]) == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
/**
 * other_cmd_handler - Handles execution of built-in commands
 * @cmd: The array of strings representing the command and its arguments
 * @argv: The array of strings representing the command-line arguments
 * @status: A pointer to the shell status
 * @idx: The index of the command in the input sequence
 *
 * This function handles the execution of various built-in commands
 * such as 'exit', 'exit()', and 'env'.
 */
void other_cmd_handler(char **cmd, char **argv, int *status, int idx)
{
	(void)argv;
	(void)idx;
	if (_strcmp(cmd[0], "exit") == 0)
	{
		shell_exit(cmd, argv, status, idx);
	}
	else if (_strcmp(cmd[0], "exit()") == 0)
	{
		shell_exit(cmd, argv, status, idx);
	}
	else if (_strcmp(cmd[0], "env") == 0)
	{
		_env(cmd, status);
	}

}
