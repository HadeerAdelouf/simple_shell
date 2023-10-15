#include"shell.h"

/**
 *execute_command - executes shell commands
 *@command:a pointer to a character string
 *
 *Return:void
 */
void execute_command(char *command)
{
	pid_t pid = fork();
	int status;

	if (pid == 0)
	{
		char *args[] = {"/bin/sh", "-c", command, NULL};
		char *envp[] = {NULL};

		execve("/bin/sh", args, envp);
		write(STDOUT_FILENO, "Command not found\n", _strlen("Command not found\n"));
		_exit(1);
	}
	else if (pid < 0)
	{
		perror("Fork failed");
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

/**
 * _strlen - calculates the length of a string
 * @str: Pointer to the string
 *
 * Return: Length of the string
 */
int _strlen(const char *str)
{
	int Length = 0;

	if (str == NULL)
		return (Length);
	for (; str[Length] != '\0'; Length++)
		;
	return (Length);
}


/**
 *_strcmp - compare two strings
 *@first: first string
 *@second: second string
 * Return: difference of the two strings
 */

int _strcmp(char *first, char *second)
{
	int j = 0;

	while (first[j] != '\0')
	{
		if (first[j] != second[j])
			break;
		j++;
	}
	return (first[j] - second[j]);
}

