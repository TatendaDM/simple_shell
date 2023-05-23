#include "shell.h"

/**
 * remove_comments - replaces instance of '#' with '\0' function
 * @buf: string to be modified address
 *
 * Return: 0 Always;
 */

void remove_comments(char *buf)

{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}

/**
 * print_d - prints out an integer (decimal) to the base 10
 * @input: input integer
 * @fd: filedescriptor
 *
 * Return: # of char to be printed
 */

int print_d(int input, int fd)

{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - function conversion, replicator of the itoa
 * @num: #
 * @base: id base
 * @flags: flag up argument
 *
 * Return: string
 */

char *convert_number(long int num, int base, int flags)

{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_error - error message to be printed
 * @info: info struct for the return and the parameter
 * @estr: error type specification as string
 * Return: 0 if # not string, -1 number converted, on error
 */

void print_error(info_t *info, char *estr)

{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * _erratoi - string to integer conversion
 * @s: input the string to be converted
 * Return: 0 if # not string, -1 number converted, on error
 */

int _erratoi(char *s)

{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}
