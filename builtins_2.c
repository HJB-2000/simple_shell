#include "shell.h"
/**
 * num_checker - Checks if a string represents a valid number
 * @str: The string to check
 *
 * This function checks if the given string represents a valid number
 * by iterating through each character and verifying if it's a digit.
 *
 * Return: 1 if the string is a valid number, 0 otherwise
 */
int num_checker(char *str)
{
	int a = 0;

	if (!str)
	{
		return (0);
	}
	while (str[a])
	{
		if (str[a] < '0' || str[a] > '9')
		{
			return (0);
		}
		a++;
	}
	return (1);
}
/**
 * _atoi - Converts a string to an integer
 * @str: The string to convert
 *
 * This function converts a string of digits to an integer.
 *
 * Return: The converted integer
 */
int _atoi(char *str)
{
	int i = 0, num = 0;

	while (str[i])
	{
		num *= 10;
		num += (str[i] - '0');
		i++;
	}
	return (num);
}
/**
 * _env - Displays the environment variables
 * @cmd: The array of strings representing the command and its arguments
 * @status: A pointer to the shell status
 *
 * This function prints the environment variables to the standard output.
 * It uses the global variable 'environ' to access the environment variables.
 */
void _env(char **cmd, int *status)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	freearry(cmd);
	*status = 0;
}
