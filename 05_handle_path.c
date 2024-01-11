#include "shell.h"
/**
 * _getpath - Locates the full path of a command in the PATH directories
 * @input_cmd: The command for which to find the full path
 *
 * This function searches for the full path of a command by checking if
 * the command includes a '/' character. If not, it looks for the command
 * in the directories listed in the PATH environment variable.
 *
 * Return: A pointer to the full path of the command or NULL if not found
 */
char *_getpath(char *input_cmd)
{
	char *path, *cmd, *directory;
	struct stat status;
	int i = 0;

	while (input_cmd[i])
	{
		if (input_cmd[i] == '/')
		{
			if (stat(input_cmd, &status) == 0)
			{
				return (_strdup(input_cmd));
			}
			return (NULL);
		}
		i++;
	}
	path = _getenv("PATH");
	if (!path)
		return (NULL);
	for (directory = strtok(path, ":"); directory; directory = strtok(NULL, ":"))
	{
		cmd = malloc(_strlen(directory) + _strlen(input_cmd) + 2);
		if (cmd)
		{
			_strcpy(cmd, directory), _strcat(cmd, "/"), _strcat(cmd, input_cmd);
			if (stat(cmd, &status) == 0)
			{
				free(path);
				return (cmd);
			}
			free(cmd);
			cmd = NULL;
		}
	}
	free(path);
	return (NULL);
}
