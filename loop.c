#include "main.h"
/**
 * loop - loop function every time displays the prompt
 * @env: environment variable
 * @av: program name
 */
void loop(char **av, char **env)
{
	char *path, *buff = NULL, *argv[ARG_MAX];
	size_t buff_size = 0;
	int respond, mode = isatty(0), counter = 0;
	const char *delim = " \t\n\r";

	while (1)
	{
		if (mode == 1)
			write(STDOUT_FILENO, ">> ", 3);
		respond = getline(&buff, &buff_size, stdin);
		if (respond == -1)
		{
			if (mode == 1)
				write(1, "\n", 1);
			free(buff);
			exit(0);
		}
		comment(buff);
		buff[respond - 1] = '\0';
		counter++;
		parse_arguments(buff, argv,  delim);
		if (argv[0] == NULL)
		{
			continue;
		}
		if (_builtin_cmd(buff, argv) != 0)
		{
			free_argv(argv);
			continue;
		}
		else
		{
			path = get_loc(argv[0], av[0], mode, counter);
			if (path == NULL)
			{
				error_message(av[0], counter, argv[0]);
				free_argv(argv);
				continue;
			}
			cmd_execute(av, path, argv, env);
		}
		free_argv(argv);
		free(path);
	}
}
/**
 * comment - a comment message
 * @str: user input
 */
void comment(char *str)
{
	int i = 0;

	while (str[i])
	{

		if (str[i] == '#' && str[i - 1] != ' ')
			break;

		if (str[i] == '#')
			str[i] = '\0';
		i++;
	}

}
/**
 * error_message - printing error message
 * @av: program name
 * @i: the counter when the prompt enters
 * a command
 * @buff: user input
 *
 */
void error_message(char *av, int i, char *argv)
{
	int len_1, len_2, temp = i;
	char num;

	len_1 = _strlen(av);
	len_2 = _strlen(argv);
	write(2, av, len_1);
	fflush(stdin);
	write(2, ": ", 2);
	if (i < 10)
	{
		num = i + '0';
		write(2, &num, 1);
	}
	else if (i > 9 && i < 100)
	{
		num = (i / 10) + '0';
		write(2, &(num), 1);
		num = (temp % 10) + '0';
		write(2, &(num), 1);
	}
	write(2, ": ", 2);
	write(2, argv, len_2);
	write(2, ": ", 2);
	write(2, "not found\n", 10);
}
/**
 * _putchar - it does the work of normal putchar
 * @c: the input char
 * Return: a character
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
