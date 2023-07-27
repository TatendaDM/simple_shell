#include "shell.h"

/**
 * bfree - address NULLs(fication)and frees a ponter
 * @ptr: freed ponter address
 *
 * Return: 1 freed, Unfreed 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
