#include "shell.h"

/**
 * _realloc - Block memory reallocation
 * @ptr: recent/ previous block of malloc pointer
 * @old_size: recent/previous meory size
 * @new_size: the new memory size alloc
 *
 * Return: old-block name pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)

{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

/**
 * _memset - sets the bytes to be allocated to memory
 * @s: Memory area pointer
 * @b: *s's bytes
 * @n: byte amount
 * Return: (s) memory area pointer
 */

char *_memset(char *s, char b, unsigned int n)

{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * cfree - clears string var from other strings
 * @pp: string var in string
 */

void cfree(char **pp)

{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}
