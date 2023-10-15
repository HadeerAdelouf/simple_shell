#include"shell.h"
/**
 * main - my simple shell function
 * Return:void
 */

int main(void)
{
	char input[MAX_IN_SIZE];
	char *token;
	const char *Prompt = "($) ";

	while (1)
	{
		write(STDOUT_FILENO, Prompt, _strlen(Prompt));
		if (fgets(input, MAX_IN_SIZE, stdin) == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		token = strtok(input, " \t\n");
		if (token == NULL)
			continue;

		if (_strcmp(token, "exit") == 0)
			exit(0);
		if (_strcmp(token, "env") == 0)
		{
			char **env = environ;

			while (*env != NULL)
			{
				write(STDOUT_FILENO, *env, _strlen(*env));
				write(STDOUT_FILENO, "\n", 1);
				env++;
			}
			continue;
		}
		execute_command(token);
	}
	return (0);
}

