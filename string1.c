#include "shell.h"

/**
 * _strdup - duplication of a certain string
 * @str: Dupli string
 *
 * Return: Dupli string pointer
 */

char *_strdup(const char *str)

{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _putchar - shows c char and writes it to stdout
 * @c: char to be printed
 *
 * Return: Success 1, Error -1 or errno
 */

int _putchar(char c)

{
	static int i;
	static char buf[size_writeup_buf];

	if (c == flush_buf || i >= size_writeup_buf)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != flush_buf)
		buf[i++] = c;
	return (1);
}

/**
 * _strcpy - cp string
 * @dest: where the string is going(the destination)
 * @src: the point source
 *
 * Return: destin pointer
 */

char *_strcpy(char *dest, char *src)

{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _puts - illustrates as print, the string input
 * @str: the input of string for print
 *
 * Return: None
 */

void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

