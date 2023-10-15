#ifndef MAIN_H
#define MAIN_H

#define MAX_IN_SIZE 1024
#define MAX_TOKENS 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;

void execute_command(char *command);
int _strlen(const char *string);
int _strcmp(char *first, char *second);
#endif

