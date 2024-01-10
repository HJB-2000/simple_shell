#include "shell.h"

/**
 * main - Entry point for the custom shell program
 * @ac: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: The exit status of the shell program
 */
int main(int ac, char **argv)
{
	char *input = NULL;
	char **cmd = NULL;
	int status = 0, idx = 0;
	(void)ac;

	while (1)
	{
		input = read_input();
		if (input == NULL)/* ctr + D*/
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		idx++;

		cmd = split_input(input);
		if (!cmd)
		{
			continue;
		}
		if (cmd_checker(cmd[0]))
		{
			other_cmd_handler(cmd, argv, &status, idx);
		}
		else
		{
			status = _execute(cmd, argv, idx);
		}
	}
}
