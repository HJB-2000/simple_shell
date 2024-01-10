#include "shell.h"

/**
 * read_input - Reads input from the user or script
 *
 * This function reads a line of input from the user or script,
 * displaying a prompt if the input is from a terminal.
 *
 * Return: A pointer to the input string or NULL on failure or EOF
 */
char *read_input(void)
{
	char *input = NULL;
	size_t length = 0;
	ssize_t read_bytes;

	if (isatty(STDIN_FILENO))
	{
		if (write(STDOUT_FILENO, "$ ", 2) == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
	}

	read_bytes = getline(&input, &length, stdin);
	if (read_bytes == -1)
	{
		free(input);
		input = NULL;
		return (NULL);
	}

	return (input);
}

