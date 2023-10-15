#include "shell.h"
/**
 * int_len - a func  that calculates the number of digits in an integer
 * @n: a parameter intger
 * Return: the length
 */
int int_len(int n)
{
	int len = 1;
	unsigned int number;


	if (n < 0)
	{
		len++;
		number = n * -1;
	}
	else
	{
		number = n;
	}
	while (number > 9)
	{
		len++;
		number = number / 10;
	}

	return (len);
}
/**
 * _itoa - a func that converts (Integer to ASCII)
 * @num: a passing intger
 * Return: buff if not NULL.
 */
char *_itoa(int num)
{
	char *buff;
	size_t  n;
	int len = int_len(num);

	buff = malloc(len + 1);
	if (!buff)
	{
		return (NULL);
	}
	buff[len] = '\0';
	if (num < 0)
	{
		n = num * -1;
		*buff = '-';
	}
	else
		n = num;
	len--;

	do {
		*(buff + len) = (n % 10) + '0';
		n /= 10;
		len--;
	} while (n > 0);
		return (buff);
}
/**
 * _error - a function that run command
 * @n: argument
 * @arv: arv argument
 * @command: the command.
 * Return: void.
 */
void _error(denum *n, char **arv, char *command)
{
	int len;
	char *error_msg, *cnt_str;

	cnt_str = _itoa(n->cnt);
	len = _strlen(arv[0]) + _strlen(command) + _strlen(cnt_str) + 17;
	error_msg = malloc(len);
	if (!error_msg)
	{
		return;
	}
	_strcpy(error_msg, arv[0]);
	_strcat(error_msg, ": ");
	_strcat(error_msg, cnt_str);
	_strcat(error_msg, ": ");
	_strcat(error_msg, command);
	_strcat(error_msg, ": not found\n");
	_strcat(error_msg, "\0");
	write(STDOUT_FILENO, error_msg, len);
	free(error_msg);
}


/**
 * signal_handler - handler cntrl c
 * @num: num argument
 */
void signal_handler(int num)
{
	(void)num;
	write(STDOUT_FILENO, "\n$ ", _strlen("\n$ "));
}
/**
 * prompt - a shell using c
 * @arv: argument by user
 * @envp: envirement variable argument
 * @flag: flag argument for mode
 */
void prompt(char **arv, char **envp, bool flag)
{
	int x;
	size_t n = 0;
	ssize_t num_c = 0;
	char *ptr = NULL, *rgv[MAX_C];


	while (1)
	{
		if (flag && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", _strlen("$ "));
		signal(SIGINT, signal_handler);
		num_c = getline(&ptr, &n, stdin);
		if (num_c == -1)
		{
			free(ptr);
			exit(EXIT_SUCCESS);
		}
		if (ptr[num_c - 1] == '\n')
			ptr[num_c - 1] = '\0';
		ptr = trim_space(ptr);
		if (_strlen(ptr) == 0)
			continue;
		x = 0;
		rgv[x] = strtok(ptr, " \n");
		handle_exit(ptr);
		handle_path(rgv, ptr);
		while (rgv[x])
		{
			x++;
			rgv[x] = strtok(NULL, " \n");
		}
		runcmd(rgv, arv, envp);
	}
	free(ptr);
}
