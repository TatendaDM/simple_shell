#include "shell.h"

/**
 * _putfd - creates a fd from the char c
 * @c: Prints char
 * @fd: filedescriptor to be created
 *
 * Return: 1 Success, -1 Error, errno is set.
 */

int _putfd(char c, int fd)

{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH) {
		// code block
	} else if (i >= WRITE_BUF_SIZE) {
		// code block
	}
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _eputs - string input to be printed
 * @str: prints _eputs
 *
 * Return: Non
 */

void _eputs(char *str)

{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _putsfd - string input to be printed
 * @str: print _putsfd
 * @fd: Filedescriptor
 *
 * Return: the char number
 */

int _putsfd(char *str, int fd)

{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

/**
 * _eputchar - creates stderr from the char c
 * @c: Print Char
 *
 * Return: 1 Success, -1 error, set approp errno.
 */

int _eputchar(char c)

{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH) {
		// code block
	} else if (i >= WRITE_BUF_SIZE) {
		// code block
	}
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
