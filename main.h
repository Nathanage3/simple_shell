#ifndef MAIN_H
#define MAIN_H

#define BUFSIZE 1024
#define ARG_MAX 100
extern char **environ;


#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <stddef.h>

/*string.c*/
int _strcmp(char *str1, char *str2);
size_t _strlen(const char *str);
char *_strtok(char *str, const char *delim);
char *_strpbrk(const char *str1, const char *str2);
char *_strcpy(char *dest, const char *src);

/*fork.c*/
void *_memcpy(void *dest, const void *src, size_t n);
void *_realloc(void *ptr, size_t size);
int _fgetc(FILE *stream);
ssize_t _getline(char **ptr, size_t *buff_size, FILE *stream);
int cmd_execute(char **av, char *path, char **argv, char **env);
/*loop.c*/
void loop(char **av, char **env);
void comment(char *str);
void error_message(char *av, int respond, char *argv);
int _putchar(char c);

/*builtin.c*/
int _builtin_cmd(char *buff, char **argv);
void _env(void);

/*get_loc.c*/
char *place_of_path(char *path, char *argv, char *av, int mode, int counter);
char *get_loc(char *argv, char *av,  int mode, int counter);
char *_strcat(char *str1, char *str2);
char *_strchr(const char *str, int k);
char *_getenv(const char *name);
/*parse.c*/
void parse_arguments(char *buff, char **argv, const char *delim );
char *_strdup(const char *str);
int _strncmp(const char *str1, const char *str2, size_t n);

/*main.c*/
void free_argv(char **argv);
void sigint_handler(int sig);
#endif
