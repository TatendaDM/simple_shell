#include "shell.h"

/**
 * _strcat - process of uniting two strings
 * @dest: buf destin
 * @src: buffer' source
 *
 * Return: destin buf's pointer
 */

char *_strcat(char *dest, char *src)

{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

/**
 * _strlen - the length of the string to be returned
 * @s: verification of the length of the string
 *
 * Return: the length of the integer fromthe string
 */

int _strlen(char *s)

{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - compares two strings using the lexicographic mth.
 * @s1: 1st string
 * @s2: 2nd string
 *
 * Return: presents as + when s1>s2, 0 whn s1 is equal s2, - when s1 < s2
 */

int _strcmp(char *s1, char *s2)

{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - finds if the needle is in the haystack
 * @haystack: search for the hay(string)
 * @needle: the subset of the hay (string)
 *
 * Return: identification or char address in the haystack or Null
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

