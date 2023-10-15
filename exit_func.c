#include "shell.h"

/**
 * @info: A structure maintains constant function prototype.
 * Return: (0) if info.argv[0] != "exit"
 */
int Sh_exit(info_t *info)
{
	int checkexit;

	if (info->argv[1])  
	{
		checkexit = err_atoi(info->argv[1]);
		if (checkexit == -1)
		{
			info->status = 2;
			print_Error(info, "Illegal number: ");
			eput_str(info->argv[1]);
			_eput_char('\n');
			return (1);
		}
		info->err_num = err_atoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * @info: A structure to maintain constant function prototype.
 * Return: Always 0
 */
int pro_change(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	_puts("help call works. Function isn't implemented yet \n");
	if (0)
		_puts(*arg_arr); 
	return (0);
}

/**
 * @info: A structure maintain constant function prototype.
 * Return: Always 0
 */
int curnt_dir(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = get_var_env(info, "HOME=");
		if (!dir)
			chdir_ret = 
				chdir((dir = get_var_env(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!get_var_env(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(get_var_env(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = 
			chdir((dir = get_var_env(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_Error(info, "can't cd to ");
		eput_str(info->argv[1]), _eput_char('\n');
	}
	else
	{
		novel_env(info, "OLDPWD", get_var_env(info, "PWD="));
		novel_env(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
