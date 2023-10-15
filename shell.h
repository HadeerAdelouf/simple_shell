#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>
#define MAX_C 10

/**
 * struct denum - structure that contains vars
 * @cnt: lines cnt
 */
typedef struct denum
{
	int cnt;
} denum;

void prompt(char **arv, char **envp, bool flag);
char *_strcat(char *dest_ptr, char *src);
void signal_handler(int num);
char *handle_path(char **rgv, char *cmd);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
int int_len(int n);
void handle_exit(char *cmd);
void runcmd(char **rgv, char **arv, char **envp);
char *trim_space(char *comnd);
char *_strncpy(char *dest, char *source, int n);
char *get_path(char *cmd);
char *_getenv(char *name);
char **tokenize_env(char *path);
extern char **environ;
void _error(denum *n, char **arv, char *command);
#endif
