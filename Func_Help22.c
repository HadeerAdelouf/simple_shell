#include "shell.h"
/**
 * handle_path - handle the path function
 * @rgv: rgv argument
 * @cmd: command set by the user
 * Return: command for exec
 */
char *handle_path(char **rgv, char *cmd)
{
	char *path;

	path = malloc(_strlen("/bin/") + _strlen(cmd) + 1);
	if (!path)
	{
		return (NULL);
	}
	_strcpy(path, "/bin/");

	if (cmd[0] != '/' && cmd[0] != '.')
	{
		rgv[0] = _strcat(path, cmd);
		return (rgv[0]);
	}
	free(path);
	return (cmd);
}



/**
 * trim_space - remove space
 * @comnd:a pointer to a string
 * Return: comnd
 */
char *trim_space(char *comnd)
{
	char *ptrr;
	int i = 0, len;

	while (comnd[i] == ' ')
		i++;
	len = _strlen(comnd) - i + 1;
	ptrr = malloc(len + 1);
	if (!ptrr)
	{
		perror("Allocation Failed\n");
		return (NULL);
	}
	_strncpy(ptrr, comnd + i, len);
	ptrr[len] = '\0';
	_strcpy(comnd, ptrr);
	free(ptrr);
	return (comnd);
}

/**
 * handle_exit -terminate the prog when type exit
 * @str: the string to be read.
 * Return:void
 *
 */
void handle_exit(char *str)
{
	if (_strcmp("exit", str) == 0)
	{
		free(str);
		exit(EXIT_SUCCESS);
	}
}

