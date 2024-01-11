#ifndef SHELL_H
#define SHELL_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>

#define symbol " \t\n"
/*----------------------------------------*/
extern char **environ;
/*-----------------------------------------*/

char *read_input(void);
char **split_input(char *line);
int _execute(char **command, char **argv, int idx);

char *_getenv(char *variable);
char *_getpath(char *command);

/*--------strings.c---------------------------------*/
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);


/*--------tools.c-----------------*/
void freearry(char **arr);
void print_error(char *name, char *cmd, int idx);
char *_itoa(int n);
void reverse_string(char *str, int len);
/*------------------------------------*/
void other_cmd_handler(char **cmd, char **argv, int *status, int idx);
int cmd_checker(char *cmd);
/*------------------------------------*/
/*-------------------------------------*/
void shell_exit(char **cmd, char **argv, int *status, int idx);
void _env(char **cmd, int *status);
int num_checker(char *str);
int _atoi(char *str);
#endif

