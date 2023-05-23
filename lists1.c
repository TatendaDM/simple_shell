#include "shell.h"

/**
 * get_node_index - fetches where the node begins(index)
 * @head: The head list location pointer
 * @node: The node's location pointer
 *
 * Return: -1 or the node's index
 */

ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

/**
 * list_len - assess the listed list's length
 * @h: position of the first node pointer
 *
 * Return: list size
 */

size_t list_len(const list_t *h)

{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - shows the arrat of strings  in their list ie list->str
 * @head: position of the first node pointer
 *
 * Return: the strings array
 */

char **list_to_strings(list_t *head)

{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * node_starts_with - identifies the node which has a string prefix
 * @node: list head's pointer
 * @prefix: the reference string
 * @c: Match char found after prefix to match
 *
 * Return: match node or null
 */

list_t *node_starts_with(list_t *node, char *prefix, char c)

{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * print_list - shows all the list_t linked elements list
 * @h: the position of the first node pointer
 *
 * Return: list's size
 */


size_t print_list(const list_t *h)

{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}
