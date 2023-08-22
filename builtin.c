#include "main.h"
/**
 * _builtin_cmd - a builtin_cmd
 * @buff: user input
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int _builtin_cmd(char *buff, char **argv)
{

	if (_strcmp(argv[0], "exit") == 0)
	{
		free(buff);
		free_argv(argv);
		exit(0);
	}
	else if (_strcmp(argv[0], "cd") == 0)
	{
		if (argv[1] == NULL)
			chdir(getenv("HOME"));
		else
			chdir(argv[1]);
		return (1);
	}
	if (_strcmp(argv[0], "env") == 0)
	{
		_env();
		return (1);
	}
	return (0);
}
/**
 * _env - environmental variable
 *
 */
void _env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
