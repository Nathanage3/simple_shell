#include "main.h"
/**
 * get_loc - get the location of the path
 * @argv: argument vector
 * @av: av
 * @mode: mode
 * @counter: counter
 * Return: NULL if it finds the exact location of the path
 */
char *get_loc(char *argv, char *av,  int mode, int counter)
{
	char *path;
	char *full_path;

	if (_strchr(argv, '/') != NULL)
		return (_strdup(argv));

	path = _getenv("PATH");
	if (path)
	{
		full_path = place_of_path(path, argv, av, mode, counter);
		if (full_path == NULL)
			return (NULL);
		return (full_path);
	}
	return (NULL);
}
/**
 * place_of_path -  A pointer to a path
 * tha points to find the location of path
 *
 * @path: the path
 * @argv: the argument vector
 * @av: av
 * @mode: mode
 * @counter: counter
 * Return: NULL char if it exactly finds
 */
char *place_of_path(char *path, char *argv, char *av, int mode, int counter)
{
	char *temp, *token, *traverse;
	char *delm = ":";
	size_t len1, len2;
	ssize_t res;

	(void)av;
	(void)counter;
	(void)mode;
	temp = _strdup(path);
	if (temp == NULL)
		return (NULL);
	len1 = _strlen(argv);
	token = _strtok(temp, delm);

	while (token != NULL)
	{
		len2 = _strlen(token);
		traverse = (char *)malloc(len1 + len2 + 2);
		if (traverse == NULL)
		{
			free(temp);
			return (NULL);
		}
		_strcpy(traverse, token);
		_strcat(traverse, "/");
		_strcat(traverse, argv);
		/*_strcat(traverse, "\0");*/
		res = access(traverse, X_OK);
		if (res == 0)
		{
			free(temp);
			return (traverse);
		}
		free(traverse);
		token = _strtok(NULL, delm);
	}
	free(temp);
	return (NULL);
}
/**
 * _strcat - string concatination
 * @str1: the first str pointer passed to strcat
 * @str2: the second str pointer passed to strcat
 *
 * Return: The concatinated str
 */
char *_strcat(char *str1, char *str2)
{
	char *p = str1 + _strlen(str1);

	while (*str2)
	{
		*p++ = *str2++;

	}
	*p = '\0';
	return (str1);
}
/**
 * _strchr - a function that returns a string
 * when it find a char k
 * @str: the string mixed with a delimiter k
 * @k: the delimiter
 * Return: the str besore the delimiter
 */
char *_strchr(const char *str, int k)
{

	while (*str != '\0')
	{
		if (*str == k)
		{
			return ((char *)str);
		}
		str++;
	}
	if (k == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}
/**
 * _getenv - it gets an environmental variabless
 * @name: The name of the environmental variable
 * Return: the value after the '=' character
 */
char *_getenv(const char *name)
{
	size_t len = _strlen(name);
	char **env;

	for (env = environ; *env != NULL; ++env)
	{
		if (_strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			return (*env + len + 1);
		}
	}
	return (NULL);
}
