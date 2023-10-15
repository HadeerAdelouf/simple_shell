#include "shell.h"
/**
 * _strncmp - compares n bytes in str1 and str2
 * @str1: first string to be compared
 * @str2: second string to be compared
 * @n: number of bytes to be checked
 * Return: > 0 if str2 is less than str1, < 0 if str1 < str2,
 * 0 is str1 is equal to str2
 */

int _strncmp(char *str1, char *str2, int n)
{
	if (!n)
		return (0);
	if (*str1 == *str2)
		return (*str1 ? _strncmp(str1 + 1, str2 + 1, n - 1) : 0);
	if (*str1)
		return (1);
	if (*str2)
		return (-1);
	return (*str1 - *str2);
}

/**
 * _strcpy - copy a string
 * @dest: dest string arg
 * @src: source arg
 * Return: string value
 */
char *_strcpy(char *dest, char *src)
{
	int j, length = 0;

	while (src[length] != '\0')
	{
		length++;
	}
	for (j = 0; j < length; j++)
	{
		dest[j] = src[j];
	}
	dest[j] = '\0';
	return (dest);
}





/**
 * _strcat - This function appends the src string to the dest string
 * @dest_ptr: string agument
 * @str: string argument
 * Return: String
 */
char *_strcat(char *dest_ptr, char *str)
{
	int len = 0, lend = 0, j;

	while (str[len] != '\0')
	{
		len++;
	}
	while (dest_ptr[lend] != '\0')
	{
		lend++;
	}
	for (j = 0; j < len; j++)
	{
		dest_ptr[lend + j] = str[j];
	}
	dest_ptr[lend + len] = '\0';
	return (dest_ptr);
}


/**
 * _strncpy - copy n char
 * @dest: string argument
 * @source: string argument for src
 * @n: integer argument
 * Return: dest
 */
char *_strncpy(char *dest, char *source, int n)
{
	int i;

	for (i = 0; i < n && source[i] != '\0'; i++)
	{
		dest[i] = source[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}

/**
 * _strlen - length of a string
 * @str: string
 * Return: length
 */
int _strlen(char *str)
{
	int i = 0;

	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

