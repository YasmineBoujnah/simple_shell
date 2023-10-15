#include "shell.h"

/**
 * @info: A structure to maintain constant function prototype.
 * Return: Always 0
 */
int histo_list(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int Not_pseud(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_xnode(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int Yes_pseud(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (Not_pseud(info, str));

	Not_pseud(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int imprime_pseud(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * @info: A structure maintain constant function prototype.
 * Return: Always 0
 */
int pseudy(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			imprime_pseud(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			Yes_pseud(info, info->argv[i]);
		else
			imprime_pseud(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
