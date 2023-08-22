#include "main.h"
/**
 * parse_arguments - parsing input argument
 *
 * @buff: user input
 * @argv: argument vector
 * @delim: delimiter
 *
 */
void parse_arguments(char *buff, char **argv, const char *delim)
{
	char  *token;
	int ac = 0;

	token = _strtok(buff, delim);
	while (token != NULL && ac < ARG_MAX - 1)
	{
		argv[ac++] = _strdup(token);
		token = _strtok(NULL, delim);
	}
	argv[ac] = NULL;
}
/**
 * _strdup - string duplication
 * @str: string pointer
 * Return: a string pointer
 */
char *_strdup(const char *str)
{
	size_t len;
	char *dup;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	dup = (char *)malloc(len + 1);
	if (dup != NULL)
		_strcpy(dup, str);
	return (dup);
}
/**
 * _strncmp - string n compare function
 * @str1: the environment variable
 * @str2: The environment variable we are looking for
 * @n: the function compare the sting till it reaaches n
 *
 * Return: 0 on success
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; ++i)
	{
		if (str1[i] != str2[i])
		{
			return ((int)(unsigned int)str1[i] - (int)(unsigned int)str2[i]);
		}
		if (str1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
