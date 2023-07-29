#include <stddef.h>

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the converted integer
 */
int _atoi(char *s)
{
int i, sign = 1, result = 0;

if (s == NULL)
return 0;

for (i = 0; s[i] != '\0'; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
result *= 10;
result += (s[i] - '0');
}
else if (result != 0)
{
// Stop parsing if non-digit character is encountered after digits
break;
}
}

return result * sign;
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to check
 *
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return 1;
else
return 0;
}

/**
 * is_delim - checks if a character is a delimiter
 * @c: The character to check
 * @delim: The delimiter string
 *
 * Return: 1 if c is a delimiter, 0 otherwise
 */
int is_delim(char c, char *delim)
{
while (*delim)
{
if (*delim++ == c)
return 1;
}

return 0;
}
