#include "shell.h"
/**
 * _atoi - .conversion process from string to integer
 * @s: String up for conversion
 * Return: 0 if invalid string, 1 valid number converted
 */

int _atoi(char *s)

{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
 * interactive - True for an interactive mode
 * @info: struct address
 *
 * Return: 0 non-interactive, 1 interactive mode
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * _isalpha - Alphabtc char checker
 * @c: Input Char
 * Return: 0 not aphabtc,1 alphabetic
 */

int _isalpha(int c)

{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * is_delim - delimiter char checker
 * @c: Check the delimiter char
 * @delim: the delimiter string
 * Return: 1 if true, 0 if false
 */

int is_delim(char c, char *delim)

{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
