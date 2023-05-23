#include "shell.h"

/**
 * _unsetenv - Environment var removal
 * @info: Struct with arguments and functional prototype maint.
 * Return: 0 not deleted or other, 1 Remove/Delete
 * @var: infor property of the string env var
 */

int _unsetenv(info_t *info, char *var)

{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * get_environ - shows the cp array of string env
 * @info: Struct with arguments and functional prototype maint.
 * Return: 0 Always
 */

char **get_environ(info_t *info)

{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _setenv - Modif or creates a new or existing env var
 * @info: Struct with arguments and functional prototype maint.
 * @var: Property infor of the string Env Variable
 * @value: value # of the env variable
 * Return: 0 Always
 */


int _setenv(info_t *info, char *var, char *value)

{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
