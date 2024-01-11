#include "shell.h"
/**
 * freearry - Frees memory allocated for an array of strings
 * @arr: The array of strings to free
 *
 * This function frees the memory allocated for each string in the
 * array and then frees the memory allocated for the array itself.
 */
void freearry(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]), arr[i] = NULL;
	}
	free(arr), arr = NULL;
}
/**
 * print_error - Prints a command not found error message
 * @name: The name of the program
 * @cmd: The command that was not found
 * @idx: The index of the command in the input sequence
 *
 * This function prints an error message indicating that the specified
 * command was not found, including the program name, command, and index.
 */
void print_error(char *name, char *cmd, int idx)
{
	char *index;
	char error_message[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, error_message, _strlen(error_message));

	free(index);
}
/**
 * _itoa - Converts an integer to a string
 * @n: The integer to convert
 *
 * This function converts an integer to a string and returns a
 * dynamically allocated copy of the resulting string.
 *
 * Return: A pointer to the string representation of the integer
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		for (; n > 0; n /= 10)
		{
			buffer[i++] = (n % 10) + '0';
		}
	}

	buffer[i] = '\0';
	reverse_string(buffer, i);

	return (_strdup(buffer));
}
/**
 * reverse_string - Reverses a string
 * @str: The string to reverse
 * @len: The length of the string
 *
 * This function reverses the characters in a string in-place.
 */
void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	for (; start < end; start++, end--)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
	}
}
