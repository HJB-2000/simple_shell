#include "shell.h"

/**
 * _getenv - Function to retrieve the value of an environment variable
 * @variable: The name of the environment variable to look for
 *
 * Return: A pointer to the value of the environment variable,
 *         or NULL if the variable is not found
 */
char *_getenv(char *variable)
{
	char *env, *env_copy, *a, *b;
	int i = 0;

	while (environ[i])
	{
		env_copy = _strdup(environ[i]);
		a = strtok(env_copy, "=");

		if (_strcmp(a, variable) == 0)
		{
			b = strtok(NULL, "\n");
			env = _strdup(b);
			free(env_copy);
			return (env);
		}
		free(env_copy);
		env_copy = NULL;
		i++;
	}
	return (NULL);
}
