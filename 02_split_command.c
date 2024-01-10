#include "shell.h"
/**
 * split_input - Splits a string into an array
 *  of substrings based on a delimiter
 * @line: The input string to be split
 *
 * This function splits the input string into an array of substrings using
 * a specified delimiter.
 *
 * Return: An array of substrings or NULL on failure or if the input is NULL
 */
char **split_input(char *line)
{
	char *t_input = NULL, *input_copy = NULL;
	char **cmd = NULL;
	int conteur = 0, i = 0;

	if (!line)
	{
		return (NULL);
	}
	input_copy = _strdup(line);
	t_input = strtok(input_copy, symbol);
	while (t_input == NULL)
	{
		free(line), line = NULL;
		free(input_copy), input_copy = NULL;
		return (NULL);
	}
	for (conteur = 0; t_input; conteur++)
	{
		t_input = strtok(NULL, symbol);
	}
	free(input_copy), input_copy = NULL;
	cmd = malloc(sizeof(char *) * (conteur + 1));
	while (!cmd)
	{
		free(line);
		return (NULL);
	}
	t_input = strtok(line, symbol);
	for (; t_input; t_input = strtok(NULL, symbol), i++)
	{
		cmd[i] = _strdup(t_input);
	}
	free(line), line = NULL;
	cmd[i] = NULL;
	return (cmd);
}
