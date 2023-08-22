#include "main.h"
/**
 * _strcmp - str compare
 * @str1: string one
 * @str2: string two
 *
 * Return: 0 on success
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (str1[i] == str2[i])
		return (0);
	else
		return (str1[i] < str2[i] ? -1 : 1);
}
/**
 * _strtok - tokenize a string
 * @str: the input string
 * @delim: the delimiter
 *
 * Return: the separated string
 */
char *_strtok(char *str, const char *delim)
{
	static char *last;
	char *token;

	if (str != NULL)
		last = str;

	if (last == NULL)
		return (NULL);

	while (*last != '\0' && _strchr(delim, *last) != NULL)
	{
		last++;
	}
	if (*last == '\0')
	{
		return (NULL);
	}
	token = last;
	while (*last != '\0' && _strchr(delim, *last) == NULL)
	{
		last++;
	}
	if (*last != '\0')
	{
		*last++ = '\0';
	}
	else
	{
		last = NULL;
	}
	return (token);
}
/**
 * _strpbrk - string pointer break
 * @str1: first string
 * @str2: second string
 * Return: str
 */
char *_strpbrk(const char *str1, const char *str2)
{
	const char *s1 = str1, *s2;

	while (*s1)
	{
		s2 = str2;
		while (*s2)
		{
			if (*s1 == *s2)
			{
				return ((char *)s1);
			}
			s2++;
		}
		s1++;
	}
	return (NULL);
}
/**
 * _strlen - string length
 * @str: input string
 * Return: number chars
 */
size_t _strlen(const char *str)
{
	int k = 0;

	if (!str)
		return (0);

	while (*str++)
		k++;
	return (k);
}
/**
 * _strcpy - string copy
 * @dest: destination
 * @src: source
 *
 * Return: the copied str
 */
char *_strcpy(char *dest, const char *src)
{
	char *my_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (my_dest);
}
