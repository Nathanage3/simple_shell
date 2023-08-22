#include "main.h"
/**
 * cmd_execute - command execution
 * @path: the path
 * @av: av
 * @argv: argument vector
 * @env: environment variables
 * Return: 0 on success
 */
int cmd_execute(char **av, char *path, char **argv, char **env)
{
	pid_t pid;
	int res, status;

	pid = fork();
	if (pid < 0)
	{
		perror(av[0]);
		exit(1);
	}
	else if (pid == 0)
	{
		res = execve(path, argv, env);
		if (res == -1)
		{
			perror(av[0]);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
