#include "shell.h"
/**
 * main - simple shell function
 * @arc: len argument
 *
 * @arv: arv argument
 * @envp: envp argument
 * Return: 0
 */
int main(int arc, char **arv, char **envp)
{
	bool input = (arc == 1 && isatty(STDIN_FILENO));

	prompt(arv, envp, input);
	return (0);
}
