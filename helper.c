#include "shell.h"
/**
 * runcmd - a function that run command
 * @rgv: rgv argument
 * @arv: arv argument
 * @envp: envp argument
 */
void runcmd(char **rgv, char **arv, char **envp)
{
	pid_t pid;
	int stat;

	pid = fork();

	if (pid == -1)
	{
		perror("Process Error");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{

		if (execve(rgv[0], rgv, envp) == (-1))
		{
			write(STDOUT_FILENO, arv[0], _strlen(arv[0]));
			write(STDOUT_FILENO, ": No such file or directory",
			_strlen(": No such file or directory"));
			write(STDOUT_FILENO, "\n", 1);

		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&stat);
	}
}

/**
 * _strncat - Concantenates two strings
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @n: n bytes to copy from src.
 * Return: Pointer to destination string.
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}


/**
 * _strcmp -compares two strings
 * @str1: first string
 * @str2: second string
 * Return: differance
 */
int _strcmp(char *str1, char *str2)
{
	int dif = 0;

	while (*str1 == *str2 && *str1 != '\0')
	{
		str1++;
		str2++;
	}
	if (str1 != str2)
		dif = *str1 - *str2;

	return (dif);
}

