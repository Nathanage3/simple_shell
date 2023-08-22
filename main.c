#include "main.h"
/**
 * free_argv - free argument vector
 * @argv: argument vector
 */
void free_argv(char **argv)
{
	int i = 0;

	for (; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
}
/**
 * sigint_handler - control plus C handler
 * @sig: revieved signal
 */
void sigint_handler(int sig)
{
	(void)sig;
}
/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 * @env: environment variable
 *
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	(void)ac;

	signal(SIGINT, sigint_handler);
	loop(av, env);


	return (errno);
}
