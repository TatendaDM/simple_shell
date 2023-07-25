#include "shell.h"

/**
 * duplica_chars - char duplication
 * @pathstr: PATH string
 * @start: index beginning
 * @stop: finish index
 *
 * Return: pointer to a new buffer
 */

char *duplica_chars(char *pathstr, int start, int stop)

{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * checks_cmd - evaluates if the cmd is executable
 * @info: Structure information
 * @path: Pathway of the required file
 *
 * Return: Other 0, True 1
 */

int checks_cmd(info_t *info, char *path)

{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * search_path - searchs for the cmd related to the PATH string
 * @info: structure information
 * @pathstr: the full string PAth
 * @cmd: search cmd prototype
 *
 * Return: show the pathway if the cmd is NULL or not found
 */

char *search_path(info_t *info, char *pathstr, char *cmd)

{
	curr_pos = 0, int i = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

