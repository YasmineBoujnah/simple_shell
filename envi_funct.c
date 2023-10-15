#include "shell.h"

/**
 * @info: a structure to maintain constant function prototype.
 *  Return: Always 0
 */
int mon_new_var(info_t *info)
{
	if (info->argc != 3)
	{
		eput_str("Incorrect number of arguements\n");
		return (1);
	}
	if (novel_env(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * @info: Structure that maintain constant function prototype
 * @Nom: environment variable's name
 *
 * Return: the value
 */
char *get_var_env(info_t *info, const char *Nom)
{
	list_t *node = info->env;
	char *ptr;

	while (node)
	{
		ptr = start_with(node->str, Nom);
		if (ptr && *ptr)
			return (ptr);
		node = node->next;
	}
	return (NULL);
}

/**
 * @info: A structure tthat maintain constant function prototype.
 * Return: Always 0
 */
int Mon_envir(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * @info: A structure that maintain constant function prototype.
 * Return: Always 0
 */
int envir_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

/**
 * @info: A structure to maintain constant function prototype.
 *  Return: Always 0
 */
int unset_env_var(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		eput_str("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		delete_var(info, info->argv[i]);

	return (0);
}
