#include "main.h"
/**
 * cmd_execute - command execution
 * @path: the path
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
/**
 *
ssize_t _getline(char **ptr, size_t *buff_size, FILE *stream)
{
	int ch;
	size_t len = 0, new_size;
	char *new_ptr;

	if (!ptr || !buff_size || !stream)
		return (-1);
	while (1)
	{
		ch = _fgetc(stream);
		if (ch == EOF || ch == '\n')
		{
			if (len == 0 && ch == EOF)
				return (-1);
			if (len + 1 >= *buff_size)
			{
				new_size = *buff_size * 2;
				new_ptr = (char *)_realloc(*ptr, new_size);
				if (new_ptr == NULL)
				{
					return (-1);
				}
				*ptr = new_ptr;
				*buff_size = new_size;
			}
			(*ptr)[len] = '\';
			return (len);
		}
		if (len + 1 >= *buff_size)
		{
			new_size = *buff_size * 2;
			new_ptr = (char *)_realloc(*ptr, new_size);
			if (new_ptr == NULL)
			{
				return (-1);
			}
			*ptr = new_ptr;
			*buff_size = new_size;
		}
		(*ptr)[len++] = ch;
	}
}
*
 *
int _fgetc(FILE *stream)
{

	if (stream == NULL || stream ->_IO_read_ptr >= _IO_read_end)
	{
		return (EOF);
	}
	return ((unsigned char) *(stream ->_IO_read_ptr++));
}
*
 *
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;
	size_t copy_size, old_size;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);

	if (new_ptr == NULL)
	{
		return (NULL);
	}
	if (ptr != NULL)
	{
		copy_size = size;
		old_size = *((size_t)ptr - 1);
		if (old_size < copy_size)
		{
			copy_size = old_size;
		}
		_memcpy(new_ptr, ptr, copy_size);
		free(ptr);
	}
	*((size_t *)new_ptr - 1) = size;
	return (new_ptr);

void *_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;

	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}
*/
